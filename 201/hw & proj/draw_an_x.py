"""
file: draw_an_x.py
Name: Wilfried Dim
Date: 02/20/2023
Section: 33
E-Mail: wtendjo1@umbc.edu
Description: This program will draw a star
"""

star_size = int(input("What is the size of the X that we want to draw? "))
# for each line it will see if the column equals the row
# or if row is equal to the star size - column - 1 (to account for shifting
# over)
for i in range(star_size):
    for j in range(star_size):
        if i == j or j == star_size - i - 1:
            print("*", end=' ')
        else:
            print(' ', end=' ')
    print()
