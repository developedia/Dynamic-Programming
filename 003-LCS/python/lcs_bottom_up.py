# Strings to find LCS of
str1, str2 = 'apple', 'apollo'

# Find length of LCS of str1 and str2 bottom up
def getLengthLCS(n1, n2):
    # Create a 2d array of size (n1 + 1) X (n2 + 1)
    lengthOfLCS = [[None for j in range(n2 + 1)] for i in range(n1 + 1)]

    # Initialize the base cases
    for i in range(n1 + 1): lengthOfLCS[i][0] = 0
    for j in range(n2 + 1): lengthOfLCS[0][j] = 0

    # Iterate till result is found
    for i in range(1, n1 + 1):
        for j in range(1, n2 + 1):
            if str1[i - 1] == str2[j - 1]:
                lengthOfLCS[i][j] = lengthOfLCS[i - 1][j - 1] + 1
            else:
                lengthOfLCS[i][j] = max(lengthOfLCS[i - 1][j], lengthOfLCS[i][j - 1])

    return lengthOfLCS[n1][n2]

if __name__ == '__main__':
    print(getLengthLCS(len(str1), len(str2)))
