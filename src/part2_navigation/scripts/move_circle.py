#!/usr/bin/env python3
# A simple ROS2 Publisher

import rclpy 
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions

from geometry_msgs.msg import Twist 

class Circle(Node): 

    def __init__(self):
        super().__init__("move_circle") 
        self.shutdown= False

        self.my_publisher = self.create_publisher(
            msg_type=Twist,
            topic="cmd_vel",
            qos_profile=10,
        ) 

        publish_rate = 10 # Hz
        self.timer = self.create_timer(
            timer_period_sec=1/publish_rate, 
            callback=self.timer_callback
        ) 
    def on_shutdown(self):
        self.get_logger().info(
            "Stopping the robot..."
    )
        self.my_publisher.publish(Twist()) 
        self.shutdown = True
        

    def timer_callback(self): 
        radius= 0.5 #meter
        linear_velocity=0.1 #meters per second [m/s]
        angular_velocity= linear_velocity/radius

        ros_time = self.get_clock().now().seconds_nanoseconds()

        topic_msg = Twist()
        topic_msg.linear.x = linear_velocity
        topic_msg.angular.z = angular_velocity
        self.my_publisher.publish(topic_msg)

        self.get_logger().info( 
            f"Linear Velocity: {topic_msg.linear.x:.2f} [m/s], "
            f"Angular Velocity: {topic_msg.angular.z:.2f} [rad/s].",
            throttle_duration_sec=1,
        )

def main(args=None): 
    rclpy.init(
        args=args,
        signal_handler_options=SignalHandlerOptions.NO
    )
    move_circle=Circle()
    try:
        rclpy.spin(move_circle)
    except KeyboardInterrupt:
        print(
            f"{move_circle.get_name()} received a shutdown request (Ctrl+C)."
        )
    finally:
        move_circle.on_shutdown()
        while not move_circle.shutdown:
            continue
        move_circle.destroy_node()
        rclpy.shutdown()



    

if __name__ == '__main__': 
    main()