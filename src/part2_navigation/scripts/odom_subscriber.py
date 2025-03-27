#!/usr/bin/env python3
# A simple ROS2 Subscriber

import rclpy 
from rclpy.node import Node

from nav_msgs.msg import Odometry
from part2_navigation_modules.tb3_tools import quaternion_to_euler

class OdomSubscriber(Node): 

    def __init__(self): 
        super().__init__("odom_subscriber") 

        self.my_subscriber = self.create_subscription(
            msg_type=Odometry,
            topic="odom",
            callback=self.msg_callback,
            qos_profile=10,
            
        ) 
        self.counter = 0

        # self.get_logger().info(
        #     f"The '{self.get_name()}' node is initialised."
        # ) 
        

    def msg_callback(self, topic_message: Odometry): 
        
            pose = topic_message.pose.pose 

            pos_x = pose.position.x
            pos_y = pose.position.y
            pos_z = pose.position.z

            roll, pitch, yaw= quaternion_to_euler(pose.orientation)

            if self.counter > 10: 
                self.counter = 0
                self.get_logger().info(
                    f"x = {pos_x:.3f} (m), y = {pos_y:.3f} (m), theta_z = {yaw:.3f} (radians)"
                )    
            else:
                self.counter += 1

            # self.get_logger().info(
            #     f"\nThe '{self.get_name()}' node heard:\n"
            #     f"  '{topic_message.data}'"
            # )

def main(args=None): 
    rclpy.init(args=args)
    my_simple_subscriber = OdomSubscriber()
    rclpy.spin(my_simple_subscriber)
    my_simple_subscriber.destroy_node()
    rclpy.shutdown() 

if __name__ == '__main__':
    main()