"""
File: knobs_and_switches.py
Name: Wilfried Dim
Date: 02/13/2023
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will determine whether the puzzle will be solved
"""


if __name__ == "__main__":
    # asks the user for the position of the knobs
    first_knob = \
        int(input("What is the position of the first knob? (Enter 1-12) "))
    second_knob = \
        int(input("What is the position of the second knob? (Enter 1-12) "))
    switch = input("What is the position of the switch? (Enter up or down) ")
    # verifies that the position of the knobs are between 1 and 12
    # before determining the final solution
    if first_knob < 1 or first_knob > 12:
        print("Knob 1 needs to be set to 1 - 12")
    elif second_knob < 1 or second_knob > 12:
        print("Knob 1 needs to be set to 1 - 12")
    elif switch != "up" or switch != "down":
        print("Invalid switch position")
    else:
        if (first_knob % 2 == 0) and (second_knob % 2 != 0) and switch == "up":
            print("The door opens, you get all the loot")
        elif (first_knob % 2 == 0) \
                and (second_knob % 2 != 0) and switch == "down":
            print("The door clanks but does not open, try again.")
        elif (first_knob % 2 != 0) and (second_knob % 2 == 0):
            print("The handle doesn't budge.")
        else:
            print("The door clanks but does not open, try again.")
