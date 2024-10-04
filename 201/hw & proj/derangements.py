def derangement(n):
    # base case if n = 0
    if n == 0:
        return 1
    else:
        # recursively calls the derangement function
        return n * (derangement(n - 1)) + (-1) ** n


if __name__ == "__main__":
    # prints the first 20 derangements
    for i in range(20):
        print(i, derangement(i))
