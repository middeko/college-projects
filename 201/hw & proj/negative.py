"""
File: negative.py
Name: Wilfried Dim
Date: 11/28/2022
Section: 32
E-mail: wtendjo1@umbc.edu
Description: This program will find the first negative number in a list
"""


def find_negative_number(list, index):
    # base case
    if list[0] < 0:
        return list[0]
    # recursive call
    else:
        return find_negative_number(list[1:], index) # index parameter not used


if __name__ == "__main__":
    # should find a negative value somewhere in a middle of a list
    exampleLst = [1, 2, -3, 4, 5]
    print(find_negative_number(exampleLst, len(exampleLst)))

    # should find a negative value in the beginning of a list
    exampleLst = [-1, 2, 3, 4, 5]
    print(find_negative_number(exampleLst, len(exampleLst)))

    # should find a negative value at the end of a list
    exampleLst = [1, 2, 3, 4, -5]
    print(find_negative_number(exampleLst, len(exampleLst)))