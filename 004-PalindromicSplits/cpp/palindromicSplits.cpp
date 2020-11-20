#include <bits/stdc++.h>
using namespace std;

// Text of interest
string text = "AABABA";

// Memo to store minimum palindromic splits
unordered_map<string, int> memo;

// Method to build keys for memo
string buildKey(int fromIndex, int toIndex) {
    return to_string(fromIndex) + " " + to_string(toIndex);
}

// Method to return minimum palindromic splits
int getMinimumPalindromicSplits(int fromIndex, int toIndex) {
    // Single character or empty text is a palindrome by itself. No split required.
    if (fromIndex >= toIndex) {
        return 0;
    }
    // If already computed return from memo
    else if (memo.find(buildKey(fromIndex, toIndex)) != memo.end()) {
        return memo[buildKey(fromIndex, toIndex)];
    }
    // Otherwise compute, store in memo and return
    else {
        // If it's a palindrome, splits required is zero
        if (text[fromIndex] == text[toIndex] && getMinimumPalindromicSplits(fromIndex + 1, toIndex - 1) == 0) {
            memo[buildKey(fromIndex, toIndex)] = 0;
        }
        // Otherwise compute min splits
        else {
            memo[buildKey(fromIndex, toIndex)] = INT_MAX;
            for (int splitAfter = fromIndex; splitAfter < toIndex; splitAfter++) {
                memo[buildKey(fromIndex, toIndex)] = min(memo[buildKey(fromIndex, toIndex)],
                    1 + getMinimumPalindromicSplits(fromIndex, splitAfter) + getMinimumPalindromicSplits(splitAfter + 1, toIndex));
            }
        }
        return memo[buildKey(fromIndex, toIndex)];
    }
}

int main() {
    int minSplits = getMinimumPalindromicSplits(0, text.length() - 1);
    cout << minSplits << endl;

    return 0;
}
