"""
File: mad_py_lib.py
Author: Wilfried Dim
Date: 2/6/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description:
    This program will display the user's favorite things after input
"""


if __name__ == "__main__":
    # asks the user for inputs for mad-lib
    place = input("What is a place name? ")
    noun_1 = input("Give an example of a noun. ")
    noun_2 = input("Give an example of another noun. ")
    family = input("Give an example of a familial relation. ")
    name = input("Give an example of a person's name. ")
    noun_3 = input("Give yet another noun. ")
    # prints out the mad-lib with the user's inputs
    print("There once was a man from", place)
    print("Who kept all his", noun_1, "in a", noun_2 + ".")
    print("\tBut his", family + ",", "named", name + ",","\n\tRan away with a", noun_3)
    print("And as for the", noun_2 + ",", place)