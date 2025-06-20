#!/usr/bin/env python3

# Import the core Python libraries for ROS and to implement ROS Actions:
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse

# Import additional rclpy libraries for multithreading and shutdown
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.signals import SignalHandlerOptions

# Import our package's action interface:
from part5_actions.action import ExploreForward
# Import other key ROS interfaces that this server will use:
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan

# Import some other useful Python Modules
from math import sqrt, pow
import numpy as np

class ExploreForwardServer(Node):

    def __init__(self):
        super().__init__("explore_forward_server_node")

        self.posx = 0.0 
        self.posy = 0.0
        self.lidar_reading = 0.0

        self.shutdown = False 

        self.await_odom = True 
        self.await_lidar = True

        self.loop_rate = self.create_rate(
            frequency=5, 
            clock=self.get_clock()
        ) 

        ## TASK: create a /cmd_vel publisher v
        self.vel_pub = self.create_publisher(
            msg_type=Twist,
            topic="/cmd_vel",
            qos_profile=10,
        )

        ## TASK: create an /odom subscriber v
        self.odom_sub = self.create_subscription(
            msg_type=Odometry,
            topic="/odom",
            callback=self.odom_callback,
            qos_profile=10,
        )

        ## TASK: create a /scan subscriber v
        self.lidar_sub = self.create_subscription(
            msg_type=LaserScan,
            topic="/scan",
            callback=self.lidar_callback,
            qos_profile=10,
        )

        # Creating the action server:
        self.actionserver = ActionServer(
            node=self, 
            action_type=ExploreForward,
            action_name="explore_forward",
            execute_callback=self.server_execution_callback,
            callback_group=ReentrantCallbackGroup(),
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback
        )

    def odom_callback(self, odom_msg: Odometry):
        """
        Callback for the /odom subscriber
        """
        ## TASK: obtain the robot's X and Y position: v
        pose = odom_msg.pose.pose 
        self.posx = pose.position.x
        self.posy = pose.position.y

        self.await_odom = False

    def lidar_callback(self, scan_msg: LaserScan):
        """
        Callback for the /scan subscriber
        """
        ## TASK: Obtain the front 40 degrees of LiDAR
        # data, filter it and return the average distance
        # (or 'nan'): v
        
        left_20_deg = scan_msg.ranges[0:21]
        right_20_deg = scan_msg.ranges[-20:] 
        front = np.array(left_20_deg + right_20_deg) 

        valid_data = front[front != float("inf")] 
        if np.shape(valid_data)[0] > 0: 
            single_point_average = valid_data.mean() 
        else:
            single_point_average = float("nan")

        self.lidar_reading = single_point_average

        self.await_lidar = False

    def goal_callback(self, goal: ExploreForward.Goal):
        """
        A callback to check that the goal inputs are valid        
        """
        goal_ok = True
        ## TASK: check the 'fwd_velocity' goal parameter is valid
        # to ensure that the robot moves forward but that it 
        # doesn't exceed is max velocity limit:
        if goal.fwd_velocity <0 and goal.fwd_velocity>1.26:


            goal_ok = False

        ## TASK: check the 'stopping_distance' goal parameter is valid
        # (it should be at least 0.2m to make sure it doesn't get too 
        # close!)
        if goal.stopping_distance <=0.2:



            goal_ok = False

        return GoalResponse.ACCEPT if goal_ok else GoalResponse.REJECT

    def cancel_callback(self, goal):
        """
        A callback to trigger cancellation of the action
        """
        self.get_logger().info('Received a cancel request...')
        return CancelResponse.ACCEPT

    def on_shutdown(self):
        """
        A method to stop the robot on shutdown
        """
        for i in range(5):
            self.vel_pub.publish(Twist())
        self.shutdown = True

    def server_execution_callback(self, goal):
        """
        A callback to encapsulate the action that is performed
        when the server is called (i.e. a valid goal is issued)
        """
        result = ExploreForward.Result()
        feedback = ExploreForward.Feedback()
        fwd_vel = goal.request.fwd_velocity
        stop_dist = goal.request.stopping_distance

        

        self.get_logger().info(
            f"\n#####\n"
            f"The '{self.get_name()}' has been called.\n"
            f"Goal:\n"
            f"  - explore at {fwd_vel:.2f} m/s\n"
            f"  - stop {stop_dist:.2f} m in front of something\n" 
            f"Here we go..."
            f"\n#####\n")

        

        # set the robot's velocity (based on the request):
        vel_cmd = Twist()
        vel_cmd.linear.x=fwd_vel

        # Get the robot's current position:
        while self.await_odom or self.await_lidar:
            continue
            
        ref_posx = self.posx
        ref_posy = self.posy
        dist_travelled = 0.0

        

        ## TASK: establish a while loop that executes until lidar readings 
        # indicate that an object is closer than the requested stopping distance
        while self.lidar_reading > stop_dist:

            ## TASK: publish a velocity command to make the robot move forward 
            # at the requested velocity...
            self.vel_pub.publish(vel_cmd)

            # check if there has been a request to cancel the action:
            if goal.is_cancel_requested:
                # stop the robot:
                for i in range(5):
                    self.vel_pub.publish(Twist())
                goal.canceled()
                self.get_logger().info(
                    f"Cancelled."
                )
                result.total_distance_travelled = dist_travelled
                result.closest_obstacle = float(self.lidar_reading)
                return result

            ## TASK: calculate the distance travelled so far:
            
            dist_travelled = sqrt(pow(ref_posx-self.posx,2)+pow(ref_posy-self.posy,2))
            self.get_logger().info(
                f"\n#####\n"
                f"\n - ref:{ref_posx}\n"
                f"\n - pos:{self.posx}\n"
                f"\n - dis:{dist_travelled}\n"
                f"\n - dis:{self.lidar_reading}\n"
                f"\n#####\n"
            )
            feedback.current_distance_travelled = dist_travelled
            goal.publish_feedback(feedback)
            self.get_logger().info(
            f"\nFEEDBACK:\n"
            f"  - Current angular position = {fdbk_current_angle:.1f} degrees.\n"
        )

            self.loop_rate.sleep() 

        for i in range(5):
            self.vel_pub.publish(Twist())

        self.get_logger().info(
            f"{self.get_name()} complete."
        )
        goal.succeed()
        result.total_distance_travelled = dist_travelled
        result.closest_obstacle = float(self.lidar_reading)
        return result
        

def main(args=None):
    rclpy.init(
        args=args,
        signal_handler_options=SignalHandlerOptions.NO
    )
    node = ExploreForwardServer()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        node.get_logger().info(
            "Starting the Server (shut down with Ctrl+C)"
        )
        executor.spin()
    except KeyboardInterrupt:
        node.get_logger().info(
            "Server shut down with Ctrl+C"
        )
    finally:
        ## TASK: complete all necessary shutdown operations.
        
        rclpy.shutdown()
        

        
if __name__ == '__main__':
    main()