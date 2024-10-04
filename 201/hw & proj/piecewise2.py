"""
File: piecewise2.py
Name: Wilfried Dim
Date: 11/28/2022
Section: 32
E-mail: wtendjo1@umbc.edu
Description: This program will calculate the value of the function
based on the user input
"""


def piecewise_function(input):
    # base case 1
    if (input == 0):
        return 0
    # base case 2
    elif(input == 1):
        return 1
    else:
        # recursive call
        return piecewise_function(input - 2) + piecewise_function(input - 1)


if __name__ == "__main__":
    # asks user for variable number
    number = int(input("Enter the value for piecewise function f() #2 : "))
    print(piecewise_function(number))

