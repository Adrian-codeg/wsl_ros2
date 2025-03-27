#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from part4_services.srv import MyNumberGame

from random import random

class NumberGameService(Node):

    def __init__(self):
        super().__init__('number_game_service')
        self.srv = self.create_service(
            srv_type=MyNumberGame, 
            srv_name='guess_the_number',
            callback=self.srv_callback
        )

        self.get_logger().info(
            f"The '{self.get_service_names_and_types()[0][0]}' service is active."
        )

        self.reset_magic_number()

    def reset_magic_number(self):
        self.magic_number = int(random() * 100)
        self.num_guesses = 0
        self.get_logger().info(
            "A secret number has been set... Game on!"
        )

    def srv_callback(self, request, response):
        correct = False
        hint = ""
        self.num_guesses += 1
        response.num_guesses = self.num_guesses
        guess = int(request.guess)
        cheat=bool(request.cheat)

        if cheat==True:
                correct=False
                hint = "The answer is "+str(self.magic_number)+"!"
                
        else:
            if guess < 0 or guess > 100:
                hint = "Error"
                self.get_logger().warning(
                    f"Invalid request '{guess}'. Guess must be between 0 and 100."
                )
            elif guess == self.magic_number:
                correct = True
                hint = "Winner"
                self.reset_magic_number()
            elif guess < self.magic_number:
                hint = "Higher"
            elif guess > self.magic_number:
                hint = "Lower"

        response.hint = hint
        response.correct = correct
        
        return response

def main():
    rclpy.init()
    node = NumberGameService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
