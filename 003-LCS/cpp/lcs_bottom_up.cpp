#include<bits/stdc++.h>
using namespace std;

// Strings to find LCS of
string str1 = "apple", str2 = "apollo";

// Method to find length of LCS of two strings
int getLengthLCS(int n1, int n2) {
    // Create array of dimention (n1 + 1) X (n2 + 1)
    int **lengthOfLCS = new int*[n1 + 1];
    for (int i = 0; i <= n1; i++) {
        lengthOfLCS[i] = new int[n2 + 1];
    }

    // Initialize the base case
    for (int i = 0; i <= n1; i++) lengthOfLCS[i][0] = 0;
    for (int j = 0; j <= n2; j++) lengthOfLCS[0][j] = 0;

    // Keep iterating until result is found
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                lengthOfLCS[i][j] = lengthOfLCS[i - 1][j - 1] + 1;
            }
            else {
                lengthOfLCS[i][j] = max(lengthOfLCS[i - 1][j], lengthOfLCS[i][j - 1]);
            }
        }
    }

    return lengthOfLCS[n1][n2];
}

int main() {
    cout << getLengthLCS(str1.length(), str2.length()) << endl;

    return 0;
}
