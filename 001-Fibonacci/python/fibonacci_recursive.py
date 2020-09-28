def fibonacci(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

if __name__ == '__main__':
    n = 6
    print("Calculating fibonacci of {}".format(n))
    print(fibonacci(n))
