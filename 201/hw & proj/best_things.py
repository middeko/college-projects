"""
File: best_things.py
Author: Wilfried Dim
Date: 2/6/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description:
    This program will display the user's favorite things after input
"""


if __name__ == "__main__":
    # asks the user for its favorite items
    favorite_film = input("Tell me your favorite movie: ")
    favorite_song = input("Tell me your favorite song: ")
    favorite_game = input("Tell me your favorite game: ")
    favorite_food = input("Tell me your favorite food: ")
    # prints out these statements with the user's favorite items
    print(favorite_film, "is a great film" + "!")
    print("I love to eat", favorite_food + "!")
    print("I heard great things about", favorite_game)
    print("Never heard of", favorite_song, "though.")
