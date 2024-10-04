"""
file: list_merge.py
Name: Wilfried Dim
Date: 02/20/2023
Section: 33
E-Mail: wtendjo1@umbc.edu
Description: This program will merge two lists
"""


if __name__ == "__main__":
    # initializes the lists and get the list size from the user
    list_size = int(input("How many elements do you want in each list? "))
    first_list = []
    second_list = []
    merged_list = []

    # asks the user for the elements of the first list
    for i in range(list_size):
        list_1_element = input("What do you want to put in the first list? ")
        first_list.append(list_1_element)

    # asks the user for the elements of the second list
    for i in range(list_size):
        list_2_element = input("What do you want to put in the second list? ")
        second_list.append(list_2_element)

    # adds the elements of the first and second list to the merged list
    for i in range(list_size):
        merged_list.append(first_list[i])
        merged_list.append(second_list[i])
    print("The first list is:", first_list)
    print("The second list is:", second_list)
    print("The merged list is:", merged_list)

