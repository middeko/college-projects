"""
File: geom_average.py
Author: Wilfried Dim
Date: 2/6/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description:
    This program will calculate and display the
geometric average of six numbers
"""


def geometric_average(first, second, third, fourth, fifth, sixth):
    # multiplies all the numbers and takes the 6th root of the total
    avg = (first * second * third * fourth * fifth * sixth) ** (1/6)
    # returns the geometric average
    return avg


if __name__ == "__main__":
    # asks the user for the numbers
    first_number = float(input("Tell me the first number: "))
    second_number = float(input("Tell me the first number: "))
    third_number = float(input("Tell me the first number: "))
    fourth_number = float(input("Tell me the first number: "))
    fifth_number = float(input("Tell me the first number: "))
    sixth_number = float(input("Tell me the first number: "))
    # passed them through the "geometric_average" function
    g_avg = geometric_average(first_number, second_number, third_number,
                              fourth_number, fifth_number, sixth_number)
    # prints the final geometric average
    print("The geometric average is", g_avg)
