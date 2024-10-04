"""
File: hex_conversion
Name: Wilfried Dim
Date: 10/18/22
Section: 32
E-mail: wtendjo1@umbc.edu
Description: This program will convert a string (Hexadecimal value) into
a decimal
"""


def main():
    # initializes list of valid hexadecimal numbers
    hex_decimal_numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    # gets hexadecimal value from user
    hexadecimal_value = input("Please enter a hexadecmial value: ")
    # reverses value (for equation purposes)
    hexadecimal_value = hexadecimal_value[::-1]
    # converts string in to a list for each character
    hex_value_list = list(hexadecimal_value)
    print(hex_value_list)

    # turns any number in the list into an integer
    for i in range(len(hexadecimal_value)):
        for element in hex_value_list:
            if element == "0" or element == "1" or element == "2" \
                    or element == "3" or element == "4" or element == "5" \
                    or element == "6" or element == "7" or element == "8" \
                    or element == "9":
                hex_value_list[i] = int(hexadecimal_value[i])
    print(hex_value_list)
    decimal_value = 0  # initializes decimal

    # adds each value into the conversion equation and increments the decimal
    # value by each answer
    for i in range(len(hexadecimal_value)):
        for element in hex_value_list:
            if element in hex_decimal_numbers:
                decimal_value += ((16 ** i) * element)
            elif element == "A":
                decimal_value += ((16 ** i) * 10)
            elif element == "B":
                decimal_value += ((16 ** i) * 11)
            elif element == "C":
                decimal_value += ((16 ** i) * 12)
            elif element == "D":
                decimal_value += ((16 ** i) * 13)
            elif element == "E":
                decimal_value += ((16 ** i) * 14)
            elif element == "F":
                decimal_value += ((16 ** i) * 15)
    # prints results
    print("The decimal value of that is:", decimal_value)


main()
