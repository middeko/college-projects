"""
file: slice_of_pi.py
Name: Wilfried Dim
Date: 02/20/2023
Section: 33
E-Mail: wtendjo1@umbc.edu
Description: This program will calculate pi using a certain sum
"""


if __name__ == "__main__":
    # asks user for upper limit
    upper_limit = int(input("Enter a positive integer L: "))
    summation = 0
    # add one to range as the amount of terms is the limit plus 1
    # for every term it will add to "summation" to get the final answer
    for i in range(upper_limit + 1):
        summation += ((-1) ** i) / ((2 * i) + 1)

    print("The sum up to L = 17  of the Leibniz formula is: ", summation)
    print("This gives our approximation of pi as", summation * 4)
