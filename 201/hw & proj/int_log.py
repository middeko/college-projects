def int_log(base, number):
    # base case if the base is greater than the number
    if number < base:
        return 0
    else:
        # recursively calls the function with the base
        # and the number divided by the base
        return 1 + int_log(base, number // base)


if __name__ == "__main__":
    # gets user input for base and number
    user_base = int(input("What is the base of the logarithm? "))
    user_number = int(input("What number are we taking the log of? "))
    # prints results
    print(int_log(user_base, user_number))
