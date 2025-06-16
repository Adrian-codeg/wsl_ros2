#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions 

from sensor_msgs.msg import LaserScan 

import numpy as np 

from nav2_msgs.srv import SaveMap
from nav_msgs.msg import OccupancyGrid

import argparse 
import os

from part2_navigation_modules.tb3_tools import quaternion_to_euler 
from math import sqrt, pow, pi 


# Import the core Python libraries for ROS and to implement ROS Actions:
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse

# Import additional rclpy libraries for multithreading and shutdown
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.signals import SignalHandlerOptions

# Import our package's action interface:
from acs6121_team16_2025.action import ExploreForward
# Import other key ROS interfaces that this server will use:
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan

# Import some other useful Python Modules
from math import sqrt, pow,radians,degrees,pi
import numpy as np
import time
import threading
import subprocess





# LAUNCH MAP SERVER
# ros2 launch nav2_map_server map_saver_server.launch.py

# open simulation world
# ros2 launch tuos_simulations acs6121.launch.py

# open actions and catographer
# ros2 launch acs6121_team16_2025 explore.launch.py

# save map
# ros2 run acs6121_team16_2025 map_saver_client.py --map-topic discover





# colcon build --packages-select acs6121_team16_2025 --symlink-install

# source ~/.bashrc








class ExploreForwardServer(Node):

    def __init__(self):
        super().__init__("explore_forward_server_node")

        self.posx = 0.0 
        self.posy = 0.0
        self.lidar_reading_front = 0.0

        # State variables
        # self.lidar_reading = 10.0
        # self.obstacle_detected = False
        self.await_odom = True
        self.await_lidar = True
        
        self.state = 'forward'
        self.movement = "forward"
        self.randomTurningDirection = "left"
        self.state_end_time = 0.0
        
        self.randomTurningDuration = 1.0
        # self.randomTurningStartTime = time.time()

        # Motion parameters
        self.minLinearSpeed = 0.3
        self.maxAngularSpeed = 0.5        
        self.min_distance = 0.6
  
        self.saveTime = time.time()
        self.randomTurningStartTime = time.time()
        # self.startTime = time.time()

        self.shutdown = False 

        self.await_odom = True 
        self.await_lidar = True

        self.save_map_client = self.create_client(SaveMap, "/map_saver/save_map")

        
        self.map_save_path = os.path.join(os.getcwd(), "ros2_ws", "src", "waffle_easy", "maps") 
        print(f"Map save to: {self.map_save_path}")
        os.makedirs(self.map_save_path, exist_ok=True)


        self.loop_rate = self.create_rate(
            frequency=5, 
            clock=self.get_clock()
        ) 

        ## TASK: create a /cmd_vel publisher v
        self.vel_pub = self.create_publisher(
            msg_type=Twist,
            topic="/cmd_vel",
            qos_profile=100,
        )

        ## TASK: create an /odom subscriber v
        self.odom_sub = self.create_subscription(
            msg_type=Odometry,
            topic="/odom",
            callback=self.odom_callback,
            qos_profile=100,
        )

        ## TASK: create a /scan subscriber v
        self.lidar_sub = self.create_subscription(
            msg_type=LaserScan,
            topic="/scan",
            callback=self.lidar_callback,
            qos_profile=100,
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

   


    def save_map(self, map_path):
        self.get_logger().info("Map saving....。")
        try:
            subprocess.run(["ros2", "run", "nav2_map_server", "map_saver_cli", "-f", "/home/student/ros2_ws/src/acs6121_team16_2025/maps/discover"], check=True)
            subprocess.run(["ros2", "run", "acs6121_team16_2025", "map_saver_client.py", "--map-topic", "/home/student/ros2_ws/src/acs6121_team16_2025/maps/discover"], check=True)

            self.get_logger().info(f"成功！Map saved successfully at {map_path}")
        except subprocess.CalledProcessError as e:
            self.get_logger().error(f"错误！Failed to save map: {e}")    


    def odom_callback(self, odom_msg: Odometry):
        """
        Callback for the /odom subscriber
        """
        ## TASK: obtain the robot's X and Y position: v
        pose = odom_msg.pose.pose 
        self.posx = pose.position.x
        self.posy = pose.position.y
        
        self.current_position = odom_msg.pose.pose.position

        (roll, pitch, yaw) = quaternion_to_euler(pose.orientation)
        self.z = abs(yaw) # abs(yaw) makes life much easier!

        self.await_odom = False

    def lidar_callback(self, scan_msg: LaserScan):
        """
        Callback for the /scan subscriber
        """
        ## TASK: Obtain the front 40 degrees of LiDAR
        # data, filter it and return the average distance
        # (or 'nan'): v

        #front
        left_20_deg = scan_msg.ranges[0:20]
        right_20_deg = scan_msg.ranges[-20:] 
        front = np.array(left_20_deg + right_20_deg) 

        #front left right
        front_left=scan_msg.ranges[5:20]
        front_right=scan_msg.ranges[-20:-5]
        front_left = np.array(front_left) 
        front_right = np.array(front_right) 

        leftFront = np.array(scan_msg.ranges[40:50])
        rightFront = np.array(scan_msg.ranges[310:320])

        valid_data_leftfront = leftFront[leftFront != float("inf")] 
        if np.shape(valid_data_leftfront)[0] > 0: 
            single_point_average_left_front = np.quantile(valid_data_leftfront,0.1)
        else:
            single_point_average_left_front = float("nan")

        valid_data_rightfront = rightFront[rightFront!= float("inf")] 
        if np.shape(valid_data_rightfront)[0] > 0: 
            single_point_average_right_front = np.quantile(valid_data_rightfront,0.1)
        else:
            single_point_average_right_front = float("nan")    

        #left right
        left=scan_msg.ranges[80:100]
        right=scan_msg.ranges[260:280]
        left = np.array(left) 
        right = np.array(right) 

        #mean right
        valid_data = front[front != float("inf")] 
        if np.shape(valid_data)[0] > 0: 
            single_point_average = np.quantile(valid_data,0.1)
        else:
            single_point_average = float("nan")

        # mean front left 
        valid_data_front_left = front_left[front_left != float("inf")] 
        if np.shape(valid_data_front_left)[0] > 0: 
            single_point_average_front_left = np.quantile(valid_data_front_left,0.1)
        else:
            single_point_average_front_left = float("nan")
        # mean front right
        valid_data_front_right = front_right[front_right != float("inf")] 
        if np.shape(valid_data_front_right)[0] > 0: 
            single_point_average_front_right = np.quantile(valid_data_front_right,0.1)
        else:
            single_point_average_front_right = float("nan")

        # mean left
        valid_data_left = left[left != float("inf")] 
        if np.shape(valid_data_left)[0] > 0: 
            single_point_average_left = np.quantile(valid_data_left,0.1)
        else:
            single_point_average_left = float("nan")

        #mean right
        valid_data_right = right[right != float("inf")] 
        if np.shape(valid_data_right)[0] > 0: 
            single_point_average_right = np.quantile(valid_data_right,0.1)
        else:
            single_point_average_right = float("nan")


        # store in variable front, left front left and front right
        self.lidar_reading_front = single_point_average
        self.lidar_reading_left = single_point_average_left
        self.lidar_reading_right = single_point_average_right
        self.lidar_reading_front_left = single_point_average_front_left
        self.lidar_reading_front_right = single_point_average_front_right

        self.lidar_reading_left_front= single_point_average_left_front
        self.lidar_reading_right_front= single_point_average_right_front

        criticalFrontLeft = np.array(scan_msg.ranges[0:60])
        criticalFrontRight = np.array(scan_msg.ranges[-60:])

        if np.shape(criticalFrontLeft)[0] > 0:
            criticalFrontLeft_min = criticalFrontLeft.min()
        else:
            criticalFrontLeft_min = float("nan")
        if np.shape(criticalFrontRight)[0] > 0:
            criticalFrontRight_min = criticalFrontRight.min()
        else:
            criticalFrontRight_min = float("nan")
        
        self.criticalFrontLeft_min=criticalFrontLeft_min
        self.criticalFrontRight_min=criticalFrontRight_min


        self.await_lidar = False

        # add obstacles detected
        #obstacle detected = any (range <min_distance for range in laser_scan if range >0)


    def goal_callback(self, goal: ExploreForward.Goal):
        """
        A callback to check that the goal inputs are valid        
        """
        goal_ok = True
        ## TASK: check the 'fwd_velocity' goal parameter is valid
        # to ensure that the robot moves forward but that it 
        # doesn't exceed is max velocity limit:
        if goal.fwd_velocity <0 or goal.fwd_velocity>1.26:


            goal_ok = False

        ## TASK: check the 'stopping_distance' goal parameter is valid
        # (it should be at least 0.2m to make sure it doesn't get too 
        # close!)
        # if goal.stopping_distance <=0.2:


        #     goal_ok = False

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
        
        #add Duration in goal
        duration=goal.request.duration

        self.saveTime = time.time()
        self.randomTurningStartTime = time.time()
        self.startTime = time.time()        

        self.get_logger().info(
            f"\n#####\n"
            f"Time: {(time.time()-self.startTime):.2f} \n"
            f"The '{self.get_name()}' has been called.\n"
            f"Goal:\n"
            f"  - explore at {fwd_vel:.2f} m/s\n"
            f"  - stop {self.lidar_reading_front:.2f} m in front of something\n" 
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
     
        while rclpy.ok() and not goal.is_cancel_requested and time.time() < self.startTime + 90:
            if self.startTime+15> time.time():
                if self.lidar_reading_left <self.min_distance and self.lidar_reading_right <self.min_distance:
                    self.get_logger().info(
                "Obstacle detected on both sides, TRAP.",
                # throttle_duration_sec=1,
                )
                self.state = "trap" 

                if self.saveTime + 50 < time.time(): 
                    self.saveTime = time.time() 
                    
                    map_name = "my_map"
                    map_path = os.path.join(self.map_save_path, map_name)

                    # # 在单独线程中保存地图
                    threading.Thread(target=self.save_map, args=(map_path,)).start()

                if self.state == "trap":
                    if self.lidar_reading_front > self.min_distance:
                        left_blocked = self.lidar_reading_left_front < self.min_distance and self.lidar_reading_left < self.min_distance / 2
                        right_blocked = self.lidar_reading_right_front < self.min_distance and self.lidar_reading_right < self.min_distance / 2

                        if left_blocked:
                            self.get_logger().info("Obstacle detected in front and left, forward right.")
                            self.movement = "forward_right"
                        elif right_blocked:
                            self.get_logger().info("Obstacle detected in front and right, forward left.")
                            self.movement = "forward_left"
                        else:
                            self.get_logger().info("Go across narrow lane.")
                            self.movement = "forward"

                        if self.lidar_reading_left > self.min_distance or self.lidar_reading_right > self.min_distance:
                            self.get_logger().info("Side clear, moving forward.")
                            self.movement = "forward"
                            self.state = "forward"
                    else:
                        self.get_logger().info("Obstacle detected in front, rotating in place.")
                        self.movement = "left"

                        

                if self.state == "forward":
                    critical_threshold = self.min_distance / 1.5
                    side_threshold = self.min_distance / 2

                    # Critical front-left
                    if self.lidar_reading_front_left < critical_threshold or self.criticalFrontLeft_min < critical_threshold:
                        self.get_logger().info("Critical obstacle on front-left. Turning right.")
                        self.movement = "right"
                        self.state = "right"
                    
                    # Critical front-right
                    elif self.lidar_reading_front_right < critical_threshold or self.criticalFrontRight_min < critical_threshold:
                        self.get_logger().info("Critical obstacle on front-right. Turning left.")
                        self.movement = "left"
                        self.state = "left"

                    # Obstacle directly ahead
                    elif self.lidar_reading_front < self.min_distance:
                        self.get_logger().info("Obstacle ahead. Turning right.")
                        self.movement = "right"
                        self.state = "right"  # Optional: add this for consistent state transitions

                    else:
                        if (self.lidar_reading_front_left < self.min_distance or
                            self.lidar_reading_left_front < side_threshold or
                            self.lidar_reading_left < side_threshold):
                            self.get_logger().info("Obstacle on left. Moving forward right.")
                            self.movement = "forward_right"
                        
                        elif (self.lidar_reading_front_right < self.min_distance or
                            self.lidar_reading_right_front < side_threshold or
                            self.lidar_reading_right < side_threshold):
                            self.get_logger().info("Obstacle on right. Moving forward left.")
                            self.movement = "forward_left"
                        
                        else:
                            self.get_logger().info("Clear path. Moving forward.")
                            self.movement = "forward"


                if self.state == "left": 
                    
                    if self.lidar_reading_front >self.min_distance:
                        self.state = "forward"
                        self.movement="forward"
                    else:
                        if self.lidar_reading_front_right >self.min_distance and self.lidar_reading_right_front > self.min_distance/1 and self.lidar_reading_right > self.min_distance/2: 
                            self.get_logger().info(
                                "No obstacle detected on right, random trun left a little.",
                                # throttle_duration_sec=1,
                            )
                            self.state = "random_turning"
                        
                            self.randomTurningDirection = "left"
                            self.randomTurningDuration = np.random.uniform(0, 0.5)  
                            self.randomTurningStartTime = time.time()  
                        else: 
                            self.get_logger().info(
                                "Obstacle detected on right, continue turning left.",
                                # throttle_duration_sec=1,
                            )
                            self.state = "left"
                            self.movement="left"

                if self.state == "right": 

                    if self.lidar_reading_front >self.min_distance:
                        self.state = "forward"
                        self.movement="forward"
                    else:
                        if self.lidar_reading_front_left >self.min_distance and self.lidar_reading_left_front > self.min_distance/1 and self.lidar_reading_left > self.min_distance/2: 
                            self.get_logger().info(
                                "No obstacle detected on left, random turn right a little.",
                                # throttle_duration_sec=1,
                            )
                        
                            self.state = "random_turning"
                            self.randomTurningDirection = "right"
                            self.randomTurningDuration = np.random.uniform(0, 0.8) 
                            self.randomTurningStartTime = time.time()  
                        else: 
                            self.get_logger().info(
                                "Obstacle detected on left, continue turning right.",
                                # throttle_duration_sec=1,
                            )
                            self.state = "right"
                            self.movement="right"

                if self.state == "random_turning": 
                    if self.lidar_reading_front > self.min_distance: 
                        self.get_logger().info(
                            "Random turn state.",
                            # throttle_duration_sec=1,
                        )
                        self.state = "forward"

                    elapsed_time = time.time() - self.randomTurningStartTime

                    if elapsed_time < self.randomTurningDuration:    
                        if self.randomTurningDirection == "left":
                            self.get_logger().info(
                                f"Random turning left for {self.randomTurningDuration - elapsed_time:.2f} more seconds.",
                                # throttle_duration_sec=1,
                            )
                            self.movement="left"

                        elif self.randomTurningDirection == "right":
                            self.get_logger().info(
                                f"Random turning left for {self.randomTurningDuration - elapsed_time:.2f} more seconds.",
                                # throttle_duration_sec=1,
                            )
                            self.movement = "right"


                    else: 
                        self.get_logger().info(
                            "Random turning finished.",
                            # throttle_duration_sec=1,
                        )
                        self.state = "forward"

                self.get_logger().info(
                    f"Current State: {self.state}.\n"
                    f"-----------------------------------------\n",
                    # throttle_duration_sec = 1,
                )

                # Set Speed
                if self.lidar_reading_front < 0.5: 
                    linearSpeed = self.minLinearSpeed
                elif self.lidar_reading_front < 2:
                    linearSpeed = self.minLinearSpeed*(1+self.lidar_reading_front-0.5)
                else:
                    linearSpeed = self.minLinearSpeed*2
                
                self.get_logger().info(
                    f"linearSpeed: {linearSpeed:.2f} m/s",
                    # throttle_duration_sec = 1,
                )

                angularSpeed = self.maxAngularSpeed

                
                if self.movement == "forward":
                    
                    vel_cmd.linear.x = linearSpeed
                    vel_cmd.angular.z = 0.0
                    self.vel_pub.publish(vel_cmd)

                elif self.movement == "left":
                    
                    vel_cmd.linear.x =  0.0
                    vel_cmd.angular.z = angularSpeed
                    self.vel_pub.publish(vel_cmd)

                elif self.movement == "right":
                    
                    vel_cmd.linear.x = 0.0
                    vel_cmd.angular.z = -angularSpeed
                    self.vel_pub.publish(vel_cmd)

                elif self.movement == "forward_left":
                    
                    vel_cmd.linear.x = linearSpeed
                    vel_cmd.angular.z = angularSpeed
                    self.vel_pub.publish(vel_cmd)

                elif self.movement == "forward_right":
                    
                    vel_cmd.linear.x = linearSpeed
                    vel_cmd.angular.z = -angularSpeed
                    self.vel_pub.publish(vel_cmd)
                # elif self.state == "moving backward":
                #     self.move_backward(linearSpeed)
                else:
                    vel_cmd.linear.x = 0.0
                    vel_cmd.angular.z = 0.0
                    self.vel_pub.publish(vel_cmd)

            else: 
                self.get_logger().info(
                    "***************\nFollow Wall mode activated.\n***************\n",
                    # throttle_duration_sec=1,
                )
                
                linearSpeed = self.minLinearSpeed
                angularSpeed = self.maxAngularSpeed

                if self.lidar_reading_front < self.min_distance*1.1: 
                    self.get_logger().info(
                        "wall detected in front, turn Right in place.",
                        # throttle_duration_sec=1,
                    )
                    print("right")
                    self.movement = "right"
        


                else:

                    if self.lidar_reading_left < self.min_distance:
                        self.get_logger().info(
                            "wall detected on left, moving forward.",
                            # throttle_duration_sec=1,
                        )
                        print("forward")
                        self.movement = "forward"


                    else:
                        self.get_logger().info(
                            "No wall detected on left, forward Left.",
                            # throttle_duration_sec=1,
                        )
                        print("forward left")
                        self.movement = "forward_left"

                    if self.lidar_reading_front_left < self.min_distance*1.5: 
                        self.get_logger().info(
                            "wall detected on left front, forward Right.",
                            # throttle_duration_sec=1,
                        )
                        print("forward right")
                        self.movement = "forward_right"

                
                    if self.movement == "forward":
                        
                        vel_cmd.linear.x = linearSpeed
                        vel_cmd.angular.z = 0.0
                        self.vel_pub.publish(vel_cmd)

                    elif self.movement == "left":
                        
                        vel_cmd.linear.x =  0.0
                        vel_cmd.angular.z = angularSpeed
                        self.vel_pub.publish(vel_cmd)
                    elif self.movement == "right":
                        
                        vel_cmd.linear.x = 0.0
                        vel_cmd.angular.z = -angularSpeed*2.5
                        self.vel_pub.publish(vel_cmd)
                    elif self.movement == "forward_left":
                        if self.lidar_reading_left > self.min_distance*2:
                            linearSpeed = linearSpeed*0.5
                        angularSpeed = self.maxAngularSpeed*(1+(self.lidar_reading_left - self.min_distance)/self.min_distance)   
                        if angularSpeed > self.maxAngularSpeed*2:
                            angularSpeed = self.maxAngularSpeed*2
                        vel_cmd.linear.x = linearSpeed
                        vel_cmd.angular.z = angularSpeed
                        self.vel_pub.publish(vel_cmd)
                    elif self.movement == "forward_right":
                        
                        vel_cmd.linear.x = linearSpeed
                        vel_cmd.angular.z = -angularSpeed
                        self.vel_pub.publish(vel_cmd)
                    # elif self.state == "moving backward":
                    #     self.move_backward(linearSpeed)
                    else:
                        vel_cmd.linear.x = 0.0
                        vel_cmd.angular.z = 0.0
                        self.vel_pub.publish(vel_cmd)




            # Publish and log 
            self.vel_pub.publish(vel_cmd)
            self.get_logger().info(
                f"[{self.state}] dist={dist_travelled:.2f}m, "
                f"linear.x={vel_cmd.linear.x:.2f}, angular.z={vel_cmd.angular.z:.2f}"
            )


            # Stop if goal duration reached
            # if self.startTime +90 <time.time():
            #     for _ in range(5):
            #         self.vel_pub.publish(Twist())  # stop the robot
            #     goal.canceled()
            #     self.get_logger().info('Over time limit. Cancelling...')
            #     result.total_distance_travelled = dist_travelled
            #     return result


            

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
                #result.closest_obstacle = float(self.lidar_reading)
                return result

            ## TASK: calculate the distance travelled so far:
            
            dist_travelled = sqrt(pow(ref_posx-self.posx,2)+pow(ref_posy-self.posy,2))
            self.get_logger().info(
                f"\n#####\n"
                f"\n - ref:{ref_posx}\n"
                f"\n - pos:{self.posx}\n"
                f"\n - dis:{dist_travelled}\n"
                f"\n - obstacles ahead:{self.lidar_reading_front}\n"
                f"\n#####\n"
            )
            feedback.current_distance_travelled = dist_travelled
            goal.publish_feedback(feedback)
            self.get_logger().info(
            f"\nFEEDBACK:\n"
            f"  - Current distance travelled = {dist_travelled:.1f} degrees.\n"
            # f"  - Map save to = {status:.1f} degrees.\n"
            
        )

            self.loop_rate.sleep() 

    # for i in range(5):
    #     self.vel_pub.publish(Twist())

    # self.get_logger().info(
    #     f"{self.get_name()} complete."
    # )
    # Save map after exploration ends
    # map_path = '/home/student/ros2_ws/src/acs6121_team16_2025/maps/explored_map'
    # map_saved = self.save_map(map_path)

    # if map_saved:
    #     self.get_logger().info("✅ Map saved after exploration.")
    #     result.status = f"Map saved to {map_path}.yaml"
    # else:
    #     self.get_logger().warn("⚠ Map save failed.")
    #     result.status = "Map save failed."

        goal.succeed()
        result.total_distance_travelled = dist_travelled
        #result.closest_obstacle = float(self.lidar_reading)
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
        node.on_shutdown()
        node.destroy_node()
        rclpy.shutdown()
        

        
if __name__ == '__main__':
    main()