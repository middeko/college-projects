"""
File: py_coin.py
Author: Wilfried Dim
Date: 2/6/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description:
    This program will display the value of any item in py-coins
"""


def conversion(py_coin_value, dollar_value):
    # converts the value of the item from dollars to its dollar value
    # in pycoins
    new_value = dollar_value / py_coin_value
    return new_value


if __name__ == '__main__':
    py_coin_dollar = float(input("How many dollars is a py-coin now? "))
    item_name = input("What item do you want to convert to py-coins? ")
    item_dollar_value = \
        int(input("How many dollars is the item you want to buy? "))
    real_value = conversion(py_coin_dollar, item_dollar_value)
    print("The value of a", item_name, "in py-coins is", real_value)

