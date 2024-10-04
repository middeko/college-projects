"""
File: leap_year.py
Name: Wilfried Dim
Date: 02/13/2023
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will determine whether the user's input is a leap
year or not
"""


if __name__ == "__main__":
    # asks user for year
    leap_year = int(input(("Enter a year: ")))
    # calculates the remainder of the year entered
    if (leap_year % 4 != 0):
        print("It is not a leap year")
    else:
        if leap_year % 100 == 0:
            if leap_year % 400 == 0:
                print("It is a leap year")
            else:
                print("It is not a leap year")
        else:
            print("It is a leap year")

