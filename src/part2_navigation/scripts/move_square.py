#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions

from geometry_msgs.msg import Twist 
from nav_msgs.msg import Odometry 

from part2_navigation_modules.tb3_tools import quaternion_to_euler 
from math import sqrt, pow, pi 

X = 0.0
Y = 0.0
Z = 0.0
count =0

class Square(Node):

    
    def __init__(self):
        super().__init__("move_square")

        self.first_message = False
        self.turn = "state1"

        self.vel_msg = Twist() 
        
        self.x = 0.0; self.y = 0.0; self.theta_z = 0.0
        self.xref = 0.0; self.yref = 0.0; self.theta_zref = 0.0
        
        self.yaw = 0.0 
        self.displacement = 0.0 

        self.vel_pub = self.create_publisher(
            msg_type=Twist,
            topic="cmd_vel",
            qos_profile=10,
        )

        self.odom_sub = self.create_subscription(
            msg_type=Odometry,
            topic="odom",
            callback=self.odom_callback,
            qos_profile=10,
        )

        ctrl_rate = 10 # hz
        self.timer = self.create_timer(
            timer_period_sec=1/ctrl_rate,
            callback=self.timer_callback,
        )

        self.shutdown = False

        self.get_logger().info(
            f"The '{self.get_name()}' node is initialised."
        )

    def on_shutdown(self):
        print("Stopping the robot...")
        self.vel_pub.publish(Twist())
        self.shutdown = True

    def odom_callback(self, msg_data: Odometry):
        global X, Y, Z  
        pose = msg_data.pose.pose 

        (roll, pitch, yaw) = quaternion_to_euler(pose.orientation) 
        

        X = pose.position.x 
        Y = pose.position.y
        
        Z = abs(yaw) # abs(yaw) makes life much easier!!

        if not self.first_message: 
            self.first_message = True
            self.xref = X
            self.yref = Y
            self.theta_zref = Z

        
   

    def timer_callback(self):
        # here is where the code to control the motion of the robot 
        # goes. Add code here to make the robot move in a square of
        # dimensions 1 x 1m...
       
        global count
        radius= sqrt(pow(1,2)+pow(1,2)) #meter
        linear_velocity=1 #meters per second [m/s]
        angular_velocity= linear_velocity/radius
        
        self.displacement=sqrt(pow(self.xref-X,2)+pow(self.yref-Y,2))
        angle=abs(self.theta_zref-Z)

        print("X position:"+str(X))
        print("Y position:"+str(Y))
        print("Z position:"+str(Z))
        print("Zref position:"+str(self.theta_zref))

        # print("displacement: " +str(self.displacement))
        # print("angle: " +str(angle))
        
        
        while count<3:
            # if self.displacement<1-0.1:
            #     self.vel_msg.angular.z=0.0
            #     self.vel_msg.linear.x= 0.3
            #     self.vel_pub.publish(self.vel_msg)
            #     self.displacement=sqrt(pow(self.xref-X,2)+pow(self.yref-Y,2))
            #     print("Displacement:"+str(self.displacement))
                
                
            #     if self.displacement>=1:
            #         self.xref=X
            #         self.yref=Y
            #         self.theta_zref=Z
            #         if angle<pi/2-0.2:
            #             self.vel_msg.linear.x= 0.0
            #             self.vel_msg.angular.z=0.3
            #             self.vel_pub.publish(self.vel_msg)
            #             angle=abs(self.theta_zref-Z)
            #             print("angle: " +str(angle))
            #             self.vel_msg.linear.x= 0.0
            #             self.vel_msg.angular.z=0.0

            #         else :
            #             self.vel_msg.linear.x= 0.0
            #             self.vel_msg.angular.z=0.0
            #             self.vel_pub.publish(self.vel_msg)
            #             self.xref=X
            #             self.yref=Y
            #             self.theta_zref=Z
            # count+=1
            
             





        
        if self.turn=="state1":          
            angle=0
            self.vel_msg.angular.z=0.0
            self.vel_msg.linear.x= 0.3
            self.vel_pub.publish(self.vel_msg)
            self.displacement=sqrt(pow(self.xref-X,2)+pow(self.yref-Y,2))
            print("Displacement:"+str(self.displacement))

            if  self.displacement>=1-0.1:
                self.xref=X
                self.yref=Y
                self.theta_zref=Z
                self.turn = "state2"
        
        
        elif self.turn=="state2":
        
        # move forwards by 1m...
            self.vel_msg.angular.z = 0.3
            self.vel_msg.linear.x=0.0
            self.vel_pub.publish(self.vel_msg)
            
            angle=abs(self.theta_zref-Z)
            print("angle: " +str(angle))
            
            count+=1
            if count>=8:
                self.turn=="state3"
            else:
                
                if angle > (pi/2-0.2):
                    self.xref=X
                    self.yref=Y
                    self.theta_zref=Z
                    self.turn="state1"
                
        else:
            print("Stopping the robot...")
            self.vel_msg.angular.z = 0.0
            self.vel_msg.linear.x=0.0
            self.vel_pub.publish(self.vel_msg)
            self.shutdown = True
        
         
        # # publish whatever velocity command has been set above:
        self.vel_pub.publish(self.vel_msg)

def main(args=None):
    rclpy.init(
        args=args,
        signal_handler_options=SignalHandlerOptions.NO,
    )
    move_square = Square()
    try:
        
        rclpy.spin(move_square)
            
    except KeyboardInterrupt:
        print(
            f"{move_square.get_name()} received a shutdown request (Ctrl+C)."
        )
    finally:
        move_square.on_shutdown()
        while not move_square.shutdown:
            continue
        move_square.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()