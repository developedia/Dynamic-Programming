def fibonacci(n):
    # Create a list of size n + 1
    result = [None] * (n + 1)

    # Fill base cases
    result[0] = 1
    result[1] = 1

    # Iterate till n
    for i in range(2, n + 1):
        result[i] = result[i - 1] + result[i - 2]

    # Return fibonacci(n)
    return result[n]

if __name__ == '__main__':
    n = 6
    print("Calculating fibonacci of {} bottom-up".format(n))
    print(fibonacci(n))
