import math

# Text of interest
text = 'AABABA'

# Memo to store minimum palindromic splits
memo = {}

def getMinimumPalindromicSplits(fromIndex, toIndex):
    # Single character or empty text is a palindrome by itself. No split required.
    if fromIndex >= toIndex:
        return 0
    # If already computed return from memo
    elif (fromIndex, toIndex) in memo:
        return memo[(fromIndex, toIndex)]
    # Otherwise compute, store in memo and return
    else:
        # If it's a palindrome, splits required is zero
        if text[fromIndex] == text[toIndex] and getMinimumPalindromicSplits(fromIndex + 1, toIndex - 1) == 0:
            memo[(fromIndex, toIndex)] = 0;
        # Otherwise compute min splits
        else:
            memo[(fromIndex, toIndex)] = math.inf
            for splitAfter in range(fromIndex, toIndex):
                memo[(fromIndex, toIndex)] = min(memo[(fromIndex, toIndex)],
                    1 + getMinimumPalindromicSplits(fromIndex, splitAfter) + getMinimumPalindromicSplits(splitAfter + 1, toIndex))
        return memo[(fromIndex, toIndex)]

if __name__ == '__main__':
    minSplits = getMinimumPalindromicSplits(0, len(text) - 1)
    print(minSplits)
