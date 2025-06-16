from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # # Path to the RViz configuration file
    # config_file = os.path.join(
    #     get_package_share_directory('tuos_simulations'),
    #     'rviz',
    #     'waffle.rviz'
    # )

    # # Include the acs6121 launch file
    # acs6121_launch = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         os.path.join(
    #             get_package_share_directory('tuos_simulations'),
    #             'launch',
    #             'acs6121.launch.py'
    #         )
    #     )
    # )

    # Include the cartographer launch file
    cartographer_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('turtlebot3_cartographer'),
                'launch',
                'cartographer.launch.py'
            )
        )
    )

    map_saver_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('nav2_map_server'),
                'launch',
                'map_saver_server.launch.py'
            )
        ),
        launch_arguments={'use_sim_time': 'false'}.items()
    )

    return LaunchDescription([
        # acs6121_launch,
        cartographer_launch,
        map_saver_launch,
        # Node(
        #     package='acs6121_team16_2025',
        #     executable='explore_server.py',
        #     name='server',
        #     output='screen',
            
        # ),

        Node(
            package='acs6121_team16_2025',
            executable='explore.py',
            name='launch',
            output='screen',
            
        )
        # Node(
        #     package='rviz2',
        #     executable='rviz2',
        #     name='rviz2',
        #     arguments=['-d', config_file],
        #     output='screen',
            
        # ),
        # Node(
        #     package='acs6121_team16_2025',
        #     executable='explore_client.py',
        #     name='client',
        #     output='screen',
            
        # ),
        # Node(
        #     package='nav2_map_server',
        #     executable='map_saver_server',
        #     name='map_saver',
        #     output='screen',
        #     parameters=[{
        #         # 'use_sim_time': True,
        #         'save_map_timeout': 5000.0,
        #         'map_topic': '/map',
        #         'free_thresh': 0.25,
        #         'occupied_thresh': 0.65,
        #         'lookup_transform_timeout_sec': 0.2
        #     }]
        # )
    ])
