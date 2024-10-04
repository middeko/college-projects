"""
File: will_it_float.py
Name: Wilfried Dim
Date: 02/13/2023
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will determine whether an object will float in water
or not
"""


if __name__ == "__main__":
    # asks user for the item's specifications
    object_name = input("What is the name of the object? ")
    object_weight = float(input("What's the object's weight? "))
    object_volume = float(input("What's the object's volume? "))
    object_density = (object_weight/object_volume)
    # determines whether the object will float or sink
    if object_density == 1000:
        print(object_name, "has neutral buoyancy")
    elif object_density > 1000:
        print(object_name, "will sink")
    else:
        print(object_name, "will float")
