#! /usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient 
from rclpy.signals import SignalHandlerOptions

from tuos_interfaces.action import CameraSweep 

class CameraSweepActionClient(Node):

    def __init__(self):
        super().__init__("camera_sweep_action_client") 
        self.goal_succeeded = False #send to true when result received
        self.goal_cancelled = False 
        self.stop = False
        self.actionclient = ActionServer(
            node=self, 
            action_type=CameraSweep,
            action_name="camera_sweep",
            execute_callback=self.server_execution_callback, 
            callback_group=ReentrantCallbackGroup(), 
            goal_callback=self.goal_callback, 
            cancel_callback=self.cancel_callback 
        )

    def send_goal(self, images=10, angle=90): 
        goal = CameraSweep.Goal()
        goal.sweep_angle = float(angle)
        goal.image_count = images

        self.actionclient.wait_for_server()

        # send the goal to the action server:
        self.send_goal_future = self.actionclient.send_goal_async(
            goal=goal,
            feedback_callback=self.feedback_callback
            )
        self.send_goal_future.add_done_callback(self.goal_response_callback)
        #This callback will be executed to inform the client of whether the server has accepted the goal or not.

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn("The goal was rejected by the server.")
            return

        self.get_logger().info("The goal was accepted by the server.")

        self.get_result_future = goal_handle.get_result_async()
        self.get_result_future.add_done_callback(self.get_result_callback)
        self._goal_handle = goal_handle

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(
            f"The action has completed.\n"
            f"Result:\n"
            f"  - Image Path = {result.image_path}"
        )
        self.goal_succeeded = True
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        fdbk_current_angle = feedback.current_angle
        fdbk_current_image = feedback.current_image
        self.get_logger().info(
            f"\nFEEDBACK:\n"
            f"  - Current angular position = {fdbk_current_angle:.1f} degrees.\n"
            f"  - Image(s) captured so far = {fdbk_current_image}."
        )
        if self.stop:
            future = self._goal_handle.cancel_goal_async()
            future.add_done_callback(self.cancel_goal)

        if fdbk_current_image>=5:
            future = self._goal_handle.cancel_goal_async()
            future.add_done_callback(self.cancel_goal)

    def cancel_goal(self, future):
        cancel_response = future.result()
        
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Goal successfully canceled')
            self.goal_cancelled = True
        else:
            self.get_logger().info('Goal failed to cancel')


def main(args=None): 
    rclpy.init(
        args=args,
        signal_handler_options=SignalHandlerOptions.NO
    )
    action_client = CameraSweepActionClient()
    future = action_client.send_goal()
    while not action_client.goal_succeeded:
        try:
            rclpy.spin_once(action_client)
            if action_client.goal_cancelled:
                break
        except KeyboardInterrupt:
            print("Ctrl+C")
            action_client.stop = True

if __name__ == '__main__':
    main()
