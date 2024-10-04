"""
file: wordle_checker.py
Name: Wilfried Dim
Date: 02/20/2023
Section: 33
E-Mail: wtendjo1@umbc.edu
Description: This program will check to see if a user's word matches the wordle
"""


if __name__ == "__main__":
    # gets the guess and solution for the user
    solution = input("Enter a solution word: ")
    guess = input("Enter the guess word: ")
    output = ""
    # if the letter is in the right "index" it will add "g" to output
    # if the letter is in the solution but in the wrong spot
    # it will add "y" to output
    for i in range(len(guess)):
        if guess[i] == solution[i]:
            output = output + "g "
        elif guess[i] in solution:
            output = output + "y "
        else:
            output = output + "_ "

    print(output)
