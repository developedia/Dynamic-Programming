# value and weight array
value = [5, 10, 25, 8, 20, 90, 3]
weight = [10, 10, 25, 5, 5, 10, 1]

memo = {}

def knapsack(n, capacity):
    # Base case
    if n == 0 or capacity == 0:
        return 0

    # If already computed then return from memo
    elif (n, capacity) in memo:
        return memo[(n, capacity)]

    # When weight is more than capacity then skip
    elif weight[n - 1] > capacity:
        memo[(n, capacity)] = knapsack(n - 1, capacity)
        return memo[(n, capacity)]

    # Return the maximum value either by skipping or by taking the n'th item
    else:
        memo[(n, capacity)] = max(knapsack(n - 1, capacity),
            value[n - 1] + knapsack(n - 1, capacity - weight[n - 1]))
        return memo[(n, capacity)]

if __name__ == '__main__':
    # number of items
    n = len(value)

    # capacity of the knapsack
    capacity = 25

    print(knapsack(n, capacity))
