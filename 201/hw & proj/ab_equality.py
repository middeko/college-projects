def ab_equal(n, k, current):
    # if n == 0 and k == 0, it prints the current word
    if n == 0:
        if k == 0:
            print(current)
    else:
        # adds a and b by recursively calling the function twice
        ab_equal(n - 1, k + 1, current + "a")
        ab_equal(n - 1, k - 1, current + "b")


if __name__ == "__main__":
    # gets length from user
    length = int(input("What length do you want to run? "))
    ab_equal(length, 0, "")
