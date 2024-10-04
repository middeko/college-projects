"""
File: find_a_plus.py
Name: Wilfried Dim
Date: 03/10/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will find if a generated grid has a plus or not
"""

# imports random library
import random


def generate_grid(m, n, seed=0):
    if seed:
        random.seed(seed)
    return [[random.choice(['.', '*']) for _ in range(n)] for _ in range(m)]


def display_grid(the_grid):
    for row in the_grid:
        print(" ".join(row))


def is_plus_there(my_grid):
    # if a "star" is found in the grid
    # the star count will increase by one
    star_count = 0
    for i in range(len(my_grid)):
        for j in range(len(my_grid[0])):
            if my_grid[i][j] == "*":
                if my_grid[i + 1][j] == "*"\
                        and my_grid[i + 1][j - 1] == "*"\
                        and my_grid[i + 1][j + 1] == "*"\
                        and my_grid[i + 2][j] == "*":
                    star_count += 1

    # if at least one star was found it will return a 1
    if star_count >= 1:
        return True
    else:
        return False


if __name__ == "__main__":
    numbers = input('Enter the dimensions (and optionally the seed): ').split()
    x = int(numbers[0])
    y = int(numbers[1])
    the_seed = int(numbers[2])
    a_grid = generate_grid(x, y, the_seed)
    # displays the grid and prints whether it has star or not
    display_grid(a_grid)
    print(is_plus_there(a_grid))
