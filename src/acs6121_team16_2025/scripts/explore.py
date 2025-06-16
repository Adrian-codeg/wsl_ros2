#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions 

from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan 

import numpy as np 
import os
import subprocess
import time
import random
import threading

from nav2_msgs.srv import SaveMap

# ros2 launch tuos_simulations acs6121.launch.py
# ros2 launch tuos_simulations cartographer.launch.py
# cd ~/ros2_ws/ && colcon build --packages-select waffle_easy --symlink-install
# source ~/.bashrc
# ros2 run waffle_easy followWall.py
# ros2 run nav2_map_server map_saver_cli -f my_map
# ros2 run nav2_map_server map_saver_cli -f /home/student/ros2_ws/src/waffle_easy/maps/my_map
# eog my_map.pgm
# eog /home/student/ros2_ws/src/waffle_easy/maps/my_map.pgm

# ros2 run turtlebot3_teleop teleop_keyboard

class FollowWall(Node):  # Based on RandomWalk.py

    def __init__(self): 
        super().__init__("follow_wall") # 节点名称

        self.shutdown = False

        self.minLinearSpeed = 0.25 # fix
        self.maxAngularSpeed = 0.5

        self.obstacleDistance = 0.6 # meters

        self.state = "moving forward" # 默认状态
        self.movement = "moving forward" # 默认动作
        self.randomTurningDirection = "left" # 默认随机转向方向
        self.randomTurningDuration = 1 # 随机转向持续时间
        self.randomTurningStartTime = time.time() # 随机转向开始时间

        self.saveTime = time.time() # 记录保存地图时间

        self.startTime = time.time() # 记录开始时间

        self.firstFollowWall = False # fix

        self.map_save_path = os.path.join(os.getcwd(), "ros2_ws", "src", "acs6121_team16_2025", "maps") # 当前工作目录下的maps文件夹
        print(f"map is saving to...: {self.map_save_path}")
        os.makedirs(self.map_save_path, exist_ok=True)  # 确保maps文件夹存在

        self.my_publisher = self.create_publisher(
            msg_type=Twist, 
            topic="/cmd_vel", 
            qos_profile=10,
        )

        self.lidar_sub = self.create_subscription(
            msg_type=LaserScan,
            topic="/scan", # 订阅"/scan"主题的LaserScan类型消息
            callback=self.lidar_callback, # 回调函数
            qos_profile=10,
        ) 

        self.get_logger().info(f"The '{self.get_name()}' node is initialised.")


    


    def save_map(self, map_path):
        self.get_logger().info("已启动后台线程以保存地图。")
        try:
            subprocess.run(
                ["ros2", "run", "acs6121_team16_2025", "map_saver_client.py", "--map-topic", "/home/student/ros2_ws/src/acs6121_team16_2025/maps/discover"], 
                check=True
            )
            self.get_logger().info(f"成功！Map saved successfully at {map_path}")
        except subprocess.CalledProcessError as e:
            self.get_logger().error(f"错误！Failed to save map: {e}")



    def lidar_callback(self, scan_data: LaserScan): 

        if self.startTime + 90 < time.time():
            print("90秒到，停止")
            self.on_shutdown()
            return

        
        # 保存地图
        if self.saveTime + 6 < time.time(): # 每5秒保存一次地图
            self.saveTime = time.time() # 更新保存时间
            # map_name = "my_map " + str(int(time.time())) # 带时间，调试用
            map_name = "my_map"
            map_path = os.path.join(self.map_save_path, map_name)

            # # 在单独线程中保存地图
            threading.Thread(target=self.save_map, args=(map_path,)).start()
            
          
        
        front = np.array(scan_data.ranges[0:30] + scan_data.ranges[-30:]) # fix
        frontLeft = np.array(scan_data.ranges[5:20]) # fix
        frontRight = np.array(scan_data.ranges[-20:-5]) # fix

       
        
        leftFront = np.array(scan_data.ranges[40:50])
        rightFront = np.array(scan_data.ranges[310:320])

        left = np.array(scan_data.ranges[80:100])
        right = np.array(scan_data.ranges[260:280])

        back = np.array(scan_data.ranges[160:200])

        # 定义一个通用过滤函数   # fix
        def filter_valid_data(data):
            return data[np.isfinite(data) & (data != 0.0)]

        front_data = filter_valid_data(front) # fix
        frontLeft_data = filter_valid_data(frontLeft)
        frontRight_data = filter_valid_data(frontRight)
        rightFront_data = filter_valid_data(rightFront)
        leftFront_data = filter_valid_data(leftFront)
        left_data = filter_valid_data(left)
        right_data = filter_valid_data(right)
        back_data = filter_valid_data(back)
    


        # 计算分位数作为检测值  # fix
        if np.shape(front_data)[0] > 0: 
            front_min = front_data.min()
        else:
            front_min = float("nan") 

        if np.shape(front_data)[0] > 0: 
            front_max = front_data.max() 
        else:
            front_max = float("nan") 

        # 正左边的最大值最小值
        if np.shape(left_data)[0] > 0: 
            left_min = left_data.min()
        else:
            left_min = float("nan") 

        if np.shape(left_data)[0] > 0: 
            left_max = left_data.max() 
        else:
            left_max = float("nan") 
    

        # 计算分位数作为检测值
        if np.shape(front_data)[0] > 0: 
            front_average = np.quantile(front_data, 0.1) 
        else:
            front_average = float("nan") 
            
        if np.shape(frontLeft_data)[0] > 0:
            frontLeft_average = np.quantile(frontLeft_data, 0.1)
        else:
            frontLeft_average = float("nan")

        if np.shape(frontRight_data)[0] > 0:
            frontRight_average = np.quantile(frontRight_data, 0.1)
        else:
            frontRight_average = float("nan")

        if np.shape(rightFront_data)[0] > 0:
            rightFront_average = np.quantile(rightFront_data, 0.1)
        else:
            rightFront_average = float("nan")

        if np.shape(leftFront_data)[0] > 0:
            leftFront_average = np.quantile(leftFront_data, 0.1)
        else:
            leftFront_average = float("nan")

        if np.shape(left_data)[0] > 0:  
            left_average = np.quantile(left_data, 0.1)
        else:
            left_average = float("nan")

        if np.shape(right_data)[0] > 0:
            right_average = np.quantile(right_data, 0.1)
        else:
            right_average = float("nan")

        if np.shape(back_data)[0] > 0:
            back_average = np.quantile(back_data, 0.1)
        else:
            back_average = float("nan")


        
        # 计算前方60度范围内的最小值，为了防止出现正对窄墙而无法检测到障碍物的情况
        criticalFrontLeft = np.array(scan_data.ranges[0:60])
        criticalFrontRight = np.array(scan_data.ranges[-60:])

        if np.shape(criticalFrontLeft)[0] > 0:
            criticalFrontLeft_min = criticalFrontLeft.min()
        else:
            criticalFrontLeft_min = float("nan")
        if np.shape(criticalFrontRight)[0] > 0:
            criticalFrontRight_min = criticalFrontRight.min()
        else:
            criticalFrontRight_min = float("nan")

        self.get_logger().info(
            f"\n"
            f"-----------------------------------------\n"
            f"Time: {(time.time()-self.startTime):.2f} \n"
            f"Front: {front_average:.2f} meters.\n"
            f"Front Min: {front_min:.2f} meters.\n"
            f"Front Max: {front_max:.2f} meters.\n"
            f"Front Left: {frontLeft_average:.2f} meters.\n"
            f"Front Right: {frontRight_average:.2f} meters.\n"
            f"Right Front: {rightFront_average:.2f} meters.\n"
            f"Left Front: {leftFront_average:.2f} meters.\n"
            f"Left: {left_average:.2f} meters.\n"
            f"Left Min: {left_min:.2f} meters.\n"
            f"Left Max: {left_max:.2f} meters.\n"
            f"Right: {right_average:.2f} meters.\n"
            f"Back: {back_average:.2f} meters.\n"
            f"Min: Front Left: {criticalFrontLeft_min:.2f} meters.\n"
            f"Min: Front Right: {criticalFrontRight_min:.2f} meters.\n"
            f"\n",
            # throttle_duration_sec = 1, # 1s内只打印一次
        ) # fix

        # 运行RandomWalk 15秒，后面改成FollowWall
        if self.startTime + 12 > time.time():  # fix

            if left_average < self.obstacleDistance and right_average < self.obstacleDistance: # 被困
                self.get_logger().info(
                    "Obstacle detected on both sides, TRAP.",
                    # throttle_duration_sec=1,
                )
                self.state = "trap"
                map_name = "my_map"
                map_path = os.path.join(self.map_save_path, map_name)

                # # 在单独线程中保存地图
                threading.Thread(target=self.save_map, args=(map_path,)).start()
            
            if self.state == "trap": # 被困
                if front_average > self.obstacleDistance: # 前方没有障碍物
                    if leftFront_average < self.obstacleDistance and left_average < self.obstacleDistance/2: 
                        self.get_logger().info(
                            "Obstacle detected in front and left, forward right.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "forward right"
                    elif rightFront_average < self.obstacleDistance and right_average < self.obstacleDistance/2: 
                        self.get_logger().info(
                            "Obstacle detected in front and right, turning left.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "forward left"
                    else:
                        self.get_logger().info(
                            "Go across narrow lane.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "moving forward"


                    if left_average > self.obstacleDistance or right_average > self.obstacleDistance: # 解除脱困
                        self.get_logger().info(
                            "Side clear, moving forward.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "moving forward"
                        self.state = "moving forward"

                else: # 前方有障碍物，原地旋转
                    self.get_logger().info(
                        "Obstacle detected in front, rotating in place.",
                        # throttle_duration_sec=1,
                    )
                    self.movement = "turning left"

                
                

            if self.state == "moving forward": # 前进

                if frontLeft_average < self.obstacleDistance/1.5 or criticalFrontLeft_min < self.obstacleDistance/1.5: # 左前有近距离障碍物 # fix
                    self.get_logger().info(
                        "Obstacle detected too close on left, turning right.",
                        # throttle_duration_sec=1,
                    )
                    self.movement = "turning right"
                    self.state = "turning right"
                elif frontRight_average < self.obstacleDistance/1.5 or criticalFrontRight_min < self.obstacleDistance/1.5: # 右侧有近距离障碍物 # fix
                    self.get_logger().info(
                        "Obstacle detected too close on right, turning left.",
                        # throttle_duration_sec=1,
                    )
                    self.movement = "turning left"
                    self.state = "turning left"
                else: # 前方没有障碍物
                    if frontLeft_average < self.obstacleDistance or leftFront_average < self.obstacleDistance/2 or left_average < self.obstacleDistance/2:
                        self.get_logger().info(
                            "Obstacle detected on left, moving forward right.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "forward right"
                    elif frontRight_average < self.obstacleDistance or rightFront_average < self.obstacleDistance/2 or right_average < self.obstacleDistance/2: # 左右侧有障碍物
                        self.get_logger().info(
                            "Obstacle detected on right, moving forward left.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "forward left"
                    else:
                        self.get_logger().info(
                            "No obstacle detected, moving forward.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "moving forward"

            if self.state == "turning left": # 左转

                if front_average > self.obstacleDistance: # 前方没有障碍物，直接直行，跳过别的
                    print("Turning left...")
                    self.movement = "moving forward"
                    self.state = "moving forward"
                else:

                    if frontRight_average > self.obstacleDistance and rightFront_average > self.obstacleDistance/1 and right_average > self.obstacleDistance/1.5: # 右侧没有障碍物，继续随机左转一点 # fix
                        self.get_logger().info(
                            "No obstacle detected on right, random trun left a little.",
                            # throttle_duration_sec=1,
                        )
                        self.state = "random turning"
                        self.randomTurningDirection = "left"
                        self.randomTurningDuration = random.uniform(0, 0.5)  # 随机转向时间（秒）
                        self.randomTurningStartTime = time.time()  # 记录开始时间
                    else: # 右侧有障碍物，继续左转
                        self.get_logger().info(
                            "Obstacle detected on right, continue turning left.",
                            # throttle_duration_sec=1,
                        )
                        self.state = "turning left"
                        self.movement = "turning left"

            if self.state == "turning right": # 右转

                if front_average > self.obstacleDistance: # 前方没有障碍物，直接直行，跳过别的
                    print("Turning right...")
                    self.movement = "moving forward"
                    self.state = "moving forward"
                else:

                    if frontLeft_average > self.obstacleDistance and leftFront_average > self.obstacleDistance/1 and left_average > self.obstacleDistance/1.5: # 左侧没有障碍物，继续随机右转一点 # fix
                        self.get_logger().info(
                            "No obstacle detected on left, random turn right a little.",
                            # throttle_duration_sec=1,
                        )
                        self.state = "random turning"
                        self.randomTurningDirection = "right"
                        self.randomTurningDuration = random.uniform(0, 0.8)  # 随机转向时间（秒）
                        self.randomTurningStartTime = time.time()  # 记录开始时间
                    else: # 左侧有障碍物，继续右转
                        self.get_logger().info(
                            "Obstacle detected on left, continue turning right.",
                            # throttle_duration_sec=1,
                        )
                        self.state = "turning right"
                        self.movement = "turning right"

            if self.state == "random turning": # 随机转向
                if front_average > self.obstacleDistance: # 前方没有障碍物，直接直行（测试）
                    self.get_logger().info(
                        "Random turning...",
                        # throttle_duration_sec=1,
                    )
                    self.state = "moving forward"
                
                    
                elapsed_time = time.time() - self.randomTurningStartTime  # 计算已过去的时间
                if elapsed_time < self.randomTurningDuration:  # 仍在转向时间内
                    # print("随机转向时间内")
                    if self.randomTurningDirection == "left":
                        self.get_logger().info(
                            f"Random turning left for {self.randomTurningDuration - elapsed_time:.2f} more seconds.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "turning left"
                        
                    elif self.randomTurningDirection == "right":
                        self.get_logger().info(
                            f"Random turning left for {self.randomTurningDuration - elapsed_time:.2f} more seconds.",
                            # throttle_duration_sec=1,
                        )
                        self.movement = "turning right"

                else: # 随机转向时间结束
                    self.get_logger().info(
                        "Random turning finished.",
                        # throttle_duration_sec=1,
                    )
                    self.state = "moving forward"

            self.get_logger().info(
                f"Current State: {self.state}.\n"
                f"-----------------------------------------\n",
                # throttle_duration_sec = 1,
            )

            # Set Speed # fix
            linearSpeed = self.minLinearSpeed
            self.get_logger().info(
                f"linearSpeed: {linearSpeed:.2f} m/s",
                # throttle_duration_sec = 1,
            )

            angularSpeed = self.maxAngularSpeed*1.5 # fix

            # 选择动作
            if self.movement == "moving forward":
                self.move_forward(linearSpeed)
            elif self.movement == "turning left":
                self.turn_left(angularSpeed)
            elif self.movement == "turning right":
                self.turn_right(angularSpeed)
            elif self.movement == "forward left":
                self.forward_left(linearSpeed, angularSpeed)
            elif self.movement == "forward right":
                self.forward_right(linearSpeed, angularSpeed)
            elif self.movement == "moving backward":
                self.move_backward(linearSpeed)
            else:
                self.stop()

            # # 延迟0.01秒
            # time.sleep(0.1) # 10ms

        else: # 运行15秒后，使用FollowWall方法，跟左边墙走
            self.get_logger().info(
                "***************\nFollow Wall mode activated.\n***************\n",
                # throttle_duration_sec=1,
            )
            linearSpeed = self.minLinearSpeed
            angularSpeed = self.maxAngularSpeed

            if front_average < self.obstacleDistance:  # 前方有障碍物
               
                if front_max >2.5 and self.movement != 'turning right':  # fix
                    self.get_logger().info(  # fix
                        "Not a wall, forward left.",
                        # throttle_duration_sec=1,
                    )
                    print("前面是柱子，不是墙壁，向左前方移动")
                    self.movement = "turning left"
                    
                else: # 前面真是墙壁
                    self.get_logger().info(
                        "wall detected in front, turn Right in place.",
                        # throttle_duration_sec=1,
                    )
                    print("前方有障碍物，原地右转")
                    self.movement = "turning right"
                    self.firstFollowWall = True # 第一次跟踪墙壁
            else:

                if left_average < self.obstacleDistance: # 左侧有障碍物
                    if left_max > 1.5: # 左侧的障碍物不是墙壁  # fix

                        if front_max < 1.5 and leftFront_average < 1.5: # 前面不远处是拐角墙壁
                            self.get_logger().info(
                                "A wall not far, forward.",
                                # throttle_duration_sec=1,
                            )
                            print("左侧的障碍物不是墙壁，但前面不远处是拐角墙壁，向前方移动")
                            self.movement = "moving forward"
                            self.firstFollowWall = True

                        else: 
                            self.get_logger().info( # fix
                                "Not a wall on left, forward right.",
                                # throttle_duration_sec=1,
                            )
                            print("左侧的障碍物不是墙壁，向左前方移动")
                            self.movement = "forward left"
                            self.firstFollowWall = True        

                    else:
                        self.get_logger().info(
                            "wall detected on left, moving forward.",
                            # throttle_duration_sec=1,
                        )
                        print("左侧有墙壁，向前移动")
                        self.movement = "moving forward"
                        self.firstFollowWall = True # 第一次跟踪墙壁

                else: # 左侧没有墙壁，前面也没有墙壁

                    if self.firstFollowWall == False: # 如果还没第一次跟踪墙，则直走
                        self.get_logger().info(
                            "Not start 1st following, moving forward.",
                            # throttle_duration_sec=1,
                        )
                        print("没有左侧墙壁，前面也没有墙壁，但还没第一次跟踪墙，则直走")
                        self.movement = "moving forward"


                    else: # 如果已经第一次跟踪墙，则向左前方移动

                        if front_max < 1.5 and leftFront_average < 1.5: # 前面不远处是拐角墙壁
                            self.get_logger().info(
                                "A wall not far, forward.",
                                # throttle_duration_sec=1,
                            )
                            print("左侧的障碍物不是墙壁，但前面不远处是拐角墙壁，向前方移动")
                            self.movement = "moving forward"
                            self.firstFollowWall = True

                        else: # 前面没有墙壁
                            self.get_logger().info(
                                "No wall detected on left, forward Left.",
                                # throttle_duration_sec=1,
                            )
                            print("没有左侧墙壁，前面也没有墙壁，向左前方移动")
                            self.movement = "forward left"    

                if leftFront_average < self.obstacleDistance: # 左前有障碍物 # fix
                    self.get_logger().info(
                        "wall detected on left front, forward Right.",
                        # throttle_duration_sec=1,
                    )
                    print("forward right....")
                    self.movement = "forward right"

            # 选择动作
            if self.movement == "moving forward": # fix
                self.move_forward(linearSpeed)
            elif self.movement == "turning left":
                self.turn_left(angularSpeed)
            elif self.movement == "turning right":
                self.turn_right(1.0) # angularSpeed
            elif self.movement == "forward left":
                if left_average > self.obstacleDistance*1.5: # 墙壁很远，慢一点 
                    linearSpeed = linearSpeed*0.5

                # angularSpeed = self.maxAngularSpeed*(1+(left_average - self.obstacleDistance)/self.obstacleDistance)

                # if angularSpeed > self.maxAngularSpeed*2:
                #     angularSpeed = self.maxAngularSpeed*2

                angularSpeed = 0.7
                self.forward_left(linearSpeed, angularSpeed)
            elif self.movement == "forward right":
                self.forward_right(linearSpeed, angularSpeed)
            elif self.movement == "moving backward":
                self.move_backward(linearSpeed)
            else:
                self.stop()


    # 纯移动部分
    def move_forward(self, linearSpeed):
        topic_msg = Twist()
        topic_msg.linear.x = linearSpeed
        topic_msg.linear.y = 0.0
        topic_msg.linear.z = 0.0
        topic_msg.angular.x = 0.0
        topic_msg.angular.y = 0.0
        topic_msg.angular.z = 0.0
        self.my_publisher.publish(topic_msg)
        self.get_logger().info(
            f"Moving forward at {topic_msg.linear.x:.2f} [m/s].",
            throttle_duration_sec=1,
        )


    def move_backward(self, linearSpeed):
        topic_msg = Twist()
        topic_msg.linear.x = -linearSpeed
        topic_msg.linear.y = 0.0
        topic_msg.linear.z = 0.0
        topic_msg.angular.x = 0.0
        topic_msg.angular.y = 0.0
        topic_msg.angular.z = 0.0
        self.my_publisher.publish(topic_msg)
        self.get_logger().info(
            f"Moving backward at {topic_msg.linear.x:.2f} [m/s].",
            throttle_duration_sec=1,
        )

    def turn_left(self, angularSpeed):
        topic_msg = Twist()
        topic_msg.linear.x = 0.0
        topic_msg.linear.y = 0.0
        topic_msg.linear.z = 0.0
        topic_msg.angular.x = 0.0
        topic_msg.angular.y = 0.0
        topic_msg.angular.z = angularSpeed
        self.my_publisher.publish(topic_msg)
        self.get_logger().info(
            f"Turning left at {topic_msg.angular.z:.2f} [rad/s].",
            throttle_duration_sec=1,
        )

    def turn_right(self, angularSpeed):
        topic_msg = Twist()
        topic_msg.linear.x = 0.0
        topic_msg.linear.y = 0.0
        topic_msg.linear.z = 0.0
        topic_msg.angular.x = 0.0
        topic_msg.angular.y = 0.0
        topic_msg.angular.z = -angularSpeed
        self.my_publisher.publish(topic_msg)
        self.get_logger().info(
            f"Turning right at {topic_msg.angular.z:.2f} [rad/s].",
            throttle_duration_sec=1,
        )

    def forward_left(self, linearSpeed, angularSpeed):
        topic_msg = Twist()
        topic_msg.linear.x = linearSpeed
        topic_msg.linear.y = 0.0
        topic_msg.linear.z = 0.0
        topic_msg.angular.x = 0.0
        topic_msg.angular.y = 0.0
        topic_msg.angular.z = angularSpeed
        self.my_publisher.publish(topic_msg)
        self.get_logger().info(
            f"Moving forward left at {topic_msg.linear.x:.2f} [m/s].",
            throttle_duration_sec=1,
        )

    def forward_right(self, linearSpeed, angularSpeed):
        topic_msg = Twist()
        topic_msg.linear.x = linearSpeed
        topic_msg.linear.y = 0.0
        topic_msg.linear.z = 0.0
        topic_msg.angular.x = 0.0
        topic_msg.angular.y = 0.0
        topic_msg.angular.z = -angularSpeed
        self.my_publisher.publish(topic_msg)
        self.get_logger().info(
            f"Moving forward right at {topic_msg.linear.x:.2f} [m/s].",
            throttle_duration_sec=1,
        )

    def stop(self):
        topic_msg = Twist()
        topic_msg.linear.x = 0.0
        topic_msg.linear.y = 0.0
        topic_msg.linear.z = 0.0
        topic_msg.angular.x = 0.0
        topic_msg.angular.y = 0.0
        topic_msg.angular.z = 0.0
        self.my_publisher.publish(topic_msg)
        self.get_logger().info(
            "Stopping the robot...",
            throttle_duration_sec=1,
        )

    def on_shutdown(self):
        self.get_logger().info(
            "Stopping the robot..."
        )
        self.my_publisher.publish(Twist()) 
        self.shutdown = True
        self.stop()

def main(args=None):
    rclpy.init(
        args=args,
        signal_handler_options=SignalHandlerOptions.NO
    )
    node = FollowWall()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("Shutdown request (Ctrl+C) detected...\n")
        
    finally:
        node.on_shutdown() 
        while not node.shutdown: 
            continue
        node.destroy_node()
        rclpy.shutdown() 

if __name__ == '__main__':
    main()