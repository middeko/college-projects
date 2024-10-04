"""
File: which_month.py
Name: Wilfried Dim
Date: 9/18/22
Section: 33
E-mail: wtendjo1@umbc.edu
Description:
    This program will determine what month it is after time elapses
"""


if __name__ == "__main__":
    # asks user for original month
    original_month = int(input("What month are we starting in"
                               "(enter as an int) ?: "))
    if (original_month < 1 or original_month > 12):
        print("That is not a month between 1 and 12")
    # asks user how many months in the future to go
    elif (original_month >= 1 and original_month <= 12):
        future_month = int(input("How many months in the future should we go?"
                                 ": "))
        # calculates future month and assigns it to a Month name
        month = (original_month + future_month) % 12
        if month == 1:
            month = "January"
        elif month == 2:
            month = "February"
        elif month == 3:
            month = "March"
        elif month == 4:
            month = "April"
        elif month == 5:
            month = "May"
        elif month == 6:
            month = "June"
        elif month == 7:
            month = "July"
        elif month == 8:
            month = "August"
        elif month == 9:
            month = "September"
        elif month == 10:
            month = "October"
        elif month == 11:
            month = "November"
        elif month == 0:
            month = "December"
    # prints final result
        print("The month will be", month)

