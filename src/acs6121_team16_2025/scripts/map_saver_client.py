#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from nav2_msgs.srv import SaveMap
from nav_msgs.msg import OccupancyGrid

from ament_index_python.packages import get_package_share_directory
import cv2
import numpy as np

import yaml 
import argparse 
import os
class MapSaverClient(Node):

    
    def __init__(self):
        super().__init__('number_game_client')

        self.map_received_count = 0
        self.map_data_saved = False

        self.map_sub = self.create_subscription(
            msg_type=OccupancyGrid,
            topic="/map",
            callback=self.map_callback,
            qos_profile=10,
        ) 
        self.lastest_map=None

        self.client = self.create_client(
            srv_type=SaveMap, 
            srv_name='map_saver/save_map'
        ) 

        #create CLI for full request input

        
        cli = argparse.ArgumentParser() 
        cli.add_argument(
            "-mf", "--map-topic", type=str, default="/map"
        ) 
        cli.add_argument(
            "-mu", "--map-url",type=str, default="/map"
        ) 
        cli.add_argument(
            "-mm", "--map-mode", type=str, default="trinary"
        ) 
        cli.add_argument(
            "-ft", "--free-thresh",type=float,default=0.25
        ) 
        cli.add_argument(
            "-of", "--occupied-thresh",type=float,default=0.65
        ) 
        self.args = cli.parse_args() 


        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(
                "Waiting for service..."
            ) 

    def map_callback(self, msg): 
        self.map_received_count += 1

        # Log map size info for each message received
        self.get_logger().info(
        f'[{self.map_received_count}] Map received: {msg.info.width}x{msg.info.height}'
        )

        # Save map on the first time only (or change logic as needed)
        if not self.map_data_saved and self.map_received_count == 1:
            self.save_map(msg)
            self.map_data_saved = True  # Prevent repeated saves unless you reset this flag

    def save_map(self, msg):
        package_share_directory = '/home/student/ros2_ws/src/acs6121_team16_2025'
        map_name = 'explore_map'
        map_dir = os.path.join(package_share_directory, 'maps')
        os.makedirs(map_dir, exist_ok=True)

        # File paths
        image_path = os.path.join(map_dir, f'{map_name}.png')
        yaml_path = os.path.join(map_dir, f'{map_name}.yaml')

        # Convert OccupancyGrid to image
        width = msg.info.width
        height = msg.info.height
        data = np.array(msg.data).reshape((height, width))

        img = np.zeros((height, width), dtype=np.uint8)
        img[data == -1] = 128  # Unknown
        img[data == 0] = 255   # Free
        img[data == 100] = 0   # Occupied

        # Save image
        cv2.imwrite(image_path, img)
        self.get_logger().info(f'Saved map image to {image_path}')

        # Save YAML metadata
        map_metadata = {
            'image': f'{map_name}.png',
            'resolution': msg.info.resolution,
            'origin': [
                msg.info.origin.position.x,
                msg.info.origin.position.y,
                self._quaternion_to_yaw(msg.info.origin.orientation)
            ],
            'negate': 0,
            'occupied_thresh': 0.65,
            'free_thresh': 0.25
        }

        with open(yaml_path, 'w') as yaml_file:
            yaml.dump(map_metadata, yaml_file, default_flow_style=False)

        self.get_logger().info(f'Saved map metadata to {yaml_path}')
    

    def _quaternion_to_yaw(self, orientation):
        import math
        # Convert quaternion (x, y, z, w) to yaw (theta)
        x = orientation.x
        y = orientation.y
        z = orientation.z
        w = orientation.w

        siny_cosp = 2.0 * (w * z + x * y)
        cosy_cosp = 1.0 - 2.0 * (y * y + z * z)
        return math.atan2(siny_cosp, cosy_cosp)



    def send_request(self,map_topic,map_url,map_mode,free_thresh,occupied_thresh): 
        # if self.lastest_map is None: #if not response
        #     print("Error!")   
        #     return None

        request = SaveMap.Request()

        try:
            package_dir = get_package_share_directory("acs6121_team16_2025")
        except Exception as e:
            self.get_logger().error(f"Package directory not found: {e}")
            return

        maps_dir = os.path.join(package_dir, "maps")
        os.makedirs(maps_dir, exist_ok=True)

        full_map_url_path = os.path.join(maps_dir, "explore_map.png")

        request.map_topic = self.args.map_topic
        request.map_url = full_map_url_path
        request.map_mode = self.args.map_mode
        request.free_thresh = self.args.free_thresh
        request.occupied_thresh = self.args.occupied_thresh

        return self.client.call_async(request)


def main(args=None):

    
    rclpy.init(
        args=args,
        signal_handler_options=SignalHandlerOptions.NO
    )
    client = MapSaverClient()
    
    try:
        rclpy.spin(client)        
        

        client.get_logger().info(
            f"Sending the request:\n"
            f" - file: {client.args.map_topic}\n"
            f" - URL: {client.args.map_url}\n"
            f" - mode: {client.args.map_mode}\n"
            f" - free: {client.args.free_thresh}\n"
            f" - occu: {client.args.occupied_thresh}\n"

            f"   Awaiting response..."
        ) 
        #client.args.map_topic,client.args.map_url,client.args.map_mode,client.args.free_thresh,client.args.occupied_thresh
        future = client.send_request() 
        rclpy.spin_until_future_complete(client, future) 
        response = future.result() 
        
        client.get_logger().info(
            f"The server has responded with:\n"
            f" - {'Saved successfully! :)' if response.result else 'Save failed :('}\n"
            
        )   
        
        
         
    except KeyboardInterrupt:
        print("Shutdown request (Ctrl+C) detected...")
    finally:
        #shutdown node
        client.destroy_node()
        

        #shutdown client
        client.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()