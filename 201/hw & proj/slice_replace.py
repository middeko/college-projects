"""
File: slice_replace.py
Name: Wilfried Dim
Date: 11/28/2022
Section: 32
E-mail: wtendjo1@umbc.edu
Description: This program will use a replace function in order to replace
a substring/ substrings in a string
"""


def slice_replace(big_string, find_string, replace_with):
    # base case
    # returns the final string once done going through string
    if len(big_string) == 0:
        return big_string
    # if the start of the string matches "find_string", it adds "replace_with"
    # to the new string
    elif big_string[0:(len(find_string))] == find_string:
        return \
            replace_with \
            + slice_replace(big_string[len(find_string):],
                            find_string, replace_with)
    # if the start of the string does not match "find_string", it continues
    # to the next character
    else:
        return big_string[0]\
               + slice_replace(big_string[1:], find_string, replace_with)


if __name__ == "__main__":
    user_big_string = input("Enter the string to use: ")
    user_find_string = input("Enter the string to find: ")
    user_replace_with = input("Enter the string to replace it with: ")
    print(slice_replace(user_big_string, user_find_string, user_replace_with))