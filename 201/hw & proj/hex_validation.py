"""
File: hex_validation
Name: Wilfried Dim
Date: 10/18/22
Section: 32
Description: This program will determine whether the character entered by the
user is a valid hexadecimal value
"""


def main():
    # initializes valid hexadecimal values
    hex_decimal_letters = ["A", "B", "C", "D", "E", "F"]
    hex_decimal_numbers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    # gets input from user
    hex_decimal_value = input("Please enter a hexadecimal value: ")
    for element in hex_decimal_value:  # checks every character of input
        if (element in hex_decimal_letters or element in hex_decimal_numbers):
            print("Index", [hex_decimal_value.index(element)], ":", element,
                  ": is a valid hex value")
        else:
            print("Index", [hex_decimal_value.index(element)], ":", element,
                  ": is an INVALID hex value")


main()
