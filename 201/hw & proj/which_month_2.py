"""
file: which_month_2.py
Name: Wilfried Dim
Date: 02/20/2023
Section: 33
E-Mail: wtendjo1@umbc.edu
Description: This program will determine the current month after time has
elapsed
"""


if __name__ == "__main__":
    # initializes a list for each month (December = 0, January = 1, etc...)
    months = [December, January, February, March, April, May, June, July,
              August, September, October, November]
    # asks user for original month
    original_month = int(input("What month are we starting in"
                               "(enter as an int) ?: "))
    if original_month < 1 or original_month > 12:
        print("That is not a month between 1 and 12")
    # asks user how many months in the future to go
    else:
        future_month = int(input("How many months in the future should we go?"
                                 ": "))
        # calculates future month
        new_month = (original_month + future_month) % 12
        for i in range(len(months)):
            if new_month == i:
                print(months[i])
