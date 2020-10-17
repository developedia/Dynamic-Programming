# Strings to find LCS of
str1, str2 = 'apple', 'apollo'

# Memo storing LCS
memo = {}

# Method to find LCS of two strings
def getLCS(n1, n2):
    if n1 == 0 or n2 == 0:
        return ''
    elif (n1, n2) in memo:
        return memo[(n1, n2)]
    elif str1[n1 - 1] == str2[n2 - 1]:
        memo[(n1, n2)] = getLCS(n1 - 1, n2 - 1) + str1[n1 - 1]
        return memo[(n1, n2)]
    else:
        memo[(n1, n2)] = max(getLCS(n1 - 1, n2), getLCS(n1, n2 - 1), key=len)
        return memo[(n1, n2)]

# Memo storing length of LCS
memoOfLength = {}

# Method to find length of LCS of two strings
def getLengthLCS(n1, n2):
    if n1 == 0 or n2 == 0:
        return 0
    elif (n1, n2) in memoOfLength:
        return memoOfLength[(n1, n2)]
    elif str1[n1 - 1] == str2[n2 - 1]:
        memoOfLength[(n1, n2)] = getLengthLCS(n1 - 1, n2 - 1) + 1
        return memoOfLength[(n1, n2)]
    else:
        memoOfLength[(n1, n2)] = max(getLengthLCS(n1 - 1, n2), getLengthLCS(n1, n2 - 1))
        return memoOfLength[(n1, n2)]

if __name__ == '__main__':
    lcs = getLCS(len(str1), len(str2))
    print(lcs, len(lcs))

    print(getLengthLCS(len(str1), len(str2)))
