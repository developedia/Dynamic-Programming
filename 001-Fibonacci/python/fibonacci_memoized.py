memo = {}

def fibonacci(n):
    if n == 0 or n == 1:
        return 1
    elif n in memo:
        return memo[n]
    else:
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2)
        return memo[n]

if __name__ == '__main__':
    n = 6
    print("Calculating fibonacci of {} using memo".format(n))
    print(fibonacci(n))
