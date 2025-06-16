#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.signals import SignalHandlerOptions

from acs6121_team16_2025.action import ExploreForward

class ExploreForwardClient(Node):

    def __init__(self):
        super().__init__("explore_client")
        self.goal_succeeded = False
        self.goal_cancelled = False
        self.actionclient = ActionClient(
            node=self,
            action_type=ExploreForward,
            action_name="explore_forward"
        )
        self.get_logger().info("ExploreForwardClient initialized")

    def send_goal(self, vel=0.2, stop=0.6, duration=90.0):
        if not self.actionclient.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("Action server not available after 5 seconds")
            return

        goal = ExploreForward.Goal()
        goal.fwd_velocity = vel
        goal.stopping_distance = float(stop)
        goal.duration = float(duration)

        self.get_logger().info(
            f"Sending goal: vel={vel:.2f}, stop={stop:.2f}, duration={duration:.2f}"
        )
        self.send_goal_future = self.actionclient.send_goal_async(
            goal=goal,
            feedback_callback=self.feedback_callback
        )
        self.send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn("Goal rejected by server")
            return

        self.get_logger().info("Goal accepted by server")
        self._goal_handle = goal_handle
        self.get_result_future = goal_handle.get_result_async()
        self.get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(
            f"Action completed.\n"
            f"Result:\n"
            f"  - Total distance travelled = {result.total_distance_travelled:.2f} m\n"
            f"  - Status = {result.status}"
        )
        self.goal_succeeded = True

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(
            f"FEEDBACK: Current distance travelled = {feedback.current_distance_travelled:.2f} m"
        )
        # Cancel goal if distance exceeds 5 meters
        if feedback.current_distance_travelled > 20:
            if hasattr(self, '_goal_handle'):
                self.get_logger().info("Distance > 5m, cancelling goal")
                future = self._goal_handle.cancel_goal_async()
                future.add_done_callback(self.cancel_goal_callback)

    def cancel_goal_callback(self, future):
        cancel_response = future.result()
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info("Goal successfully cancelled")
            self.goal_cancelled = True
        else:
            self.get_logger().warn("Goal failed to cancel")

    def shutdown(self):
        self.get_logger().info("Shutting down client")
        if hasattr(self, '_goal_handle') and not (self.goal_succeeded or self.goal_cancelled):
            future = self._goal_handle.cancel_goal_async()
            future.add_done_callback(self.cancel_goal_callback)
        self.destroy_node()

def main(args=None):
    rclpy.init(args=args, signal_handler_options=SignalHandlerOptions.NO)
    action_client = ExploreForwardClient()
    try:
        action_client.send_goal(vel=0.2, stop=0.5, duration=90.0)
        while rclpy.ok() and not (action_client.goal_succeeded or action_client.goal_cancelled):
            rclpy.spin_once(action_client, timeout_sec=1.0)
    except KeyboardInterrupt:
        action_client.get_logger().info("Ctrl+C detected, cancelling goal")
        if hasattr(action_client, '_goal_handle'):
            future = action_client._goal_handle.cancel_goal_async()
            future.add_done_callback(action_client.cancel_goal_callback)
            # Spin until cancellation completes
            while rclpy.ok() and not action_client.goal_cancelled:
                rclpy.spin_once(action_client, timeout_sec=1.0)
    finally:
        action_client.shutdown()
        rclpy.shutdown()

if __name__ == '__main__':
    main()