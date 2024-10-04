"""
File: rewrite_replace.py
Name: Wilfried Dim
Date: 03/10/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will replace a specified part of a string and replace
it with another string (chosen by user)
"""


def rewrite_replace(the_string, look_for, replace_with):
    # initializes the new string
    new_string = ""
    i = 0
    # until "i" is greater than the length of the string
    # it will look for the desires string and will replace it with
    # "replace with" if found
    while i < (len(the_string)):
        if the_string[i:(i + len(look_for))] == look_for:
            new_string = new_string + replace_with
            i += len(look_for)
        else:
            new_string = new_string + the_string[i]
            i += 1
    # returns the new string
    return new_string


if __name__ == "__main__":
    full_string = input("What is the total string? ")
    full_string_list = []
    for i in range(len(full_string)):
        full_string_list.append(full_string)
    look_string = input("What string should we look for? ")
    replace_string = input("What should we replace that string with? ")
    # prints out new string
    print(rewrite_replace(full_string, look_string, replace_string))
