"""
File: quasi_pal.pyThis program will
Name: Wilfried Dim
Date: 03/10/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will determine if a word is a palindrome
"""


def quasi_palindrome(word, errors):
    error_count = 0
    reversed_word = word[::-1]
    print(reversed_word)
    # if the word reversed is the same as the word
    # it will check the desired amount of errors to see if it matches
    if word == reversed_word:
        if errors == 0:
            return 1
        else:
            return 0
    # it will count the real amount of errors in the reversed word and compare
    # it to the desired amount of errors
    else:
        for i in range(len(word)):
            if reversed_word[i] != word[i]:
                error_count += 1
        if error_count == errors:
            return 1
        else:
            return 0


if __name__ == "__main__":
    Flag = True
    while Flag:
        # asks the user for word and amount of errors until the user types quit
        user_word = input("What do you want to want to check? ")
        if user_word == "quit":
            flag = False
        else:
            user_errors = int(input("How many errors do you want to allow? "))
            result = quasi_palindrome(user_word, user_errors)
            if result == 1:
                print("It was a " + str(user_errors)
                      + "-quasi-palindrome word!")
            else:
                print(
                    "It was not a " + str(user_errors)
                    + "-quasi-palindrome word!")

