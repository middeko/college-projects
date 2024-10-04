"""
File: fast_food.py
Name: Wilfried Dim
Date: 03/10/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will calculate the total cost of a fast food order
"""


def fast_food_receipt(order):
    # adds all the items up by determining their price
    # and adding it to the total cost
    total_cost = 0
    for element in order:
        if element == "burger" or element == "sandwich":
            total_cost += 5.00
        elif element == "fries":
            total_cost += 3.00
        elif element == "coke" \
                or element == "sprite" or element == "mountain dew":
            total_cost += 2.50
        elif element == "a burger, fries, and drink" \
                or element == "a sandwich, fries, and drink":
            total_cost += 8.50
        else:
            total_cost += 4.00
    return total_cost


if __name__ == "__main__":
    food_order = []
    flag = True
    while flag:
        # adds each item to the food_order list and passes it through
        # "fast_food_receipt" function
        item = input("What would you like to order? ")
        if item == "place order":
            flag = False
        else:
            food_order.append(item)

    total_bill = fast_food_receipt(food_order)
    # prints final total
    print("The total bill is", total_bill)
