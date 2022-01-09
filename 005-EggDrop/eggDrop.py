import math

# Memo to store previously calculated min drops
memo = {}

# Method to calculate min drops required
def getMinEggDrops(eggs, floors):
    # Base case
    if eggs == 1 or floors == 0 or floors == 1: return floors

    # Check in Memo
    if (eggs, floors) in memo: return memo[(eggs, floors)]

    # Compute, store in memo, and return
    memo[(eggs, floors)] = math.inf
    for floor in range(1, floors + 1):
        memo[(eggs, floors)] = min(memo[(eggs, floors)], 1 + max(getMinEggDrops(eggs - 1, floor - 1), getMinEggDrops(eggs, floors - floor)))
    return memo[(eggs, floors)]

if __name__ == '__main__':
    eggs, floors = 3, 15
    print(getMinEggDrops(eggs, floors))
