#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from nav2_msgs.srv import SaveMap
from nav_msgs.msg import OccupancyGrid

import argparse 
import os
class MapSaverClient(Node):

    def __init__(self):
        super().__init__('number_game_client')

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
            "-mf", "--map-topic", type=str, default="hung"
        ) 
        cli.add_argument(
            "-mu", "--map-url",type=str, default=""
        ) 
        cli.add_argument(
            "-mm", "--map-mode", type=str, default="trinary"
        ) 
        cli.add_argument(
            "-ft", "--free-thresh",default=0.25
        ) 
        cli.add_argument(
            "-of", "--occupied-thresh",default=0.65
        ) 
        self.args = cli.parse_args() 

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(
                "Waiting for service..."
            ) 

    def map_callback(self, msg): 
        self.get_logger().info('Received map data')
        self.lastest_map=msg

    def send_request(self,map_topic,map_url,map_mode,free_thresh,occupied_thresh): 
        # if self.lastest_map is None: #if not response
        #     print("Error!")   
        #     return None

        request = SaveMap.Request()

        #Add file directory
        
        # if not map_topic.startswith('~'):
        #     map_topic += '.yaml'
        home_dir=os.path.expanduser(f('~/'))
            # home_dir=os.path.expanduser(f'~/{full_path}')
        full_path=os.path.join(home_dir,map_topic)
        full_path2=os.path.join(home_dir,map_url)
        # print(full_path)
        # try:  
        #     # with open(full_path, 'w') as yaml_file:  
        #     #     yaml.dump(map_dict, full_path)  
        #     self.get_logger().info(f'Map saved to {full_path}')  
        # except Exception as e:  
        #     self.get_logger().error(f'Failed to save map to {full_path}: {e}')

        #Make a request
        request.map_topic = full_path
        request.map_url = full_path2
        request.map_mode = map_mode
        request.free_thresh = free_thresh
        request.occupied_thresh = occupied_thresh

        return self.client.call_async(request)

def main(args=None):

    
    rclpy.init(
        args=args,
        signal_handler_options=SignalHandlerOptions.NO
    )
    node = MapSaverClient()
    
    try:
        rclpy.spin(node)        
        client = MapSaverClient()

        client.get_logger().info(
            f"Sending the request:\n"
            f" - file: {client.args.map_topic}\n"
            f" - URL: {client.args.map_url}\n"
            f" - mode: {client.args.map_mode}\n"
            f" - free: {client.args.free_thresh}\n"
            f" - occu: {client.args.occupied_thresh}\n"

            f"   Awaiting response..."
        ) 

        future = client.send_request(client.args.map_topic,client.args.map_url,client.args.map_mode,client.args.free_thresh,client.args.occupied_thresh) 
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
        node.destroy_node()
        

        #shutdown client
        client.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()