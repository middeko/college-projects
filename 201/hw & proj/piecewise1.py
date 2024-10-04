"""
File: piecewise1.py
Name: Wilfried Dim
Date: 11/28/2022
Section: 32
E-mail: wtendjo1@umbc.edu
Description: This program will calculate the value of the function
based on the user input
"""


def piecewise_function(input):
    # base case
    if (input == 1):
        return 3
    else:
        # recursive call
        return 4 * piecewise_function(input - 1)


if __name__ == "__main__":
    # asks user for variable number
    number = int(input("Enter the value for piecewise function f() #1 : "))
    print(piecewise_function(number))
