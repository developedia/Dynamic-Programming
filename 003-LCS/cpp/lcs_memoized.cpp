#include<bits/stdc++.h>
using namespace std;

// Strings to find LCS of
string str1 = "apple", str2 = "apollo";

// Get the longer of two strings
string getLonger(string s1, string s2) {
    return s1.length() > s2.length() ? s1 : s2;
}

// Memo storing LCS
map<pair<int, int>, string> memo;

// Method to find LCS of two strings
string getLCS(int n1, int n2) {
    if (n1 == 0 || n2 == 0) {
        return "";
    }
    else if (memo.find(make_pair(n1, n2)) != memo.end()) {
        return memo[make_pair(n1, n2)];
    }
    else if (str1[n1 - 1] == str2[n2 - 1]) {
        memo[make_pair(n1, n2)] = getLCS(n1 - 1, n2 - 1) + str1[n1 - 1];
        return memo[make_pair(n1, n2)];
    }
    else {
        memo[make_pair(n1, n2)] = getLonger(getLCS(n1 - 1, n2), getLCS(n1, n2 - 1));
        return memo[make_pair(n1, n2)];
    }
}

// Memo storing length of LCS
map<pair<int, int>, int> memoOfLength;

// Method to find length of LCS of two strings
int getLengthLCS(int n1, int n2) {
    if (n1 == 0 || n2 == 0) {
        return 0;
    }
    else if (memoOfLength.find(make_pair(n1, n2)) != memoOfLength.end()) {
        return memoOfLength[make_pair(n1, n2)];
    }
    else if (str1[n1 - 1] == str2[n2 - 1]) {
        memoOfLength[make_pair(n1, n2)] = getLengthLCS(n1 - 1, n2 - 1) + 1;
        return memoOfLength[make_pair(n1, n2)];
    }
    else {
        memoOfLength[make_pair(n1, n2)] = max(getLengthLCS(n1 - 1, n2), getLengthLCS(n1, n2 - 1));
        return memoOfLength[make_pair(n1, n2)];
    }
}

int main() {
    string lcs = getLCS(str1.length(), str2.length());
    cout << lcs << " " << lcs.length() << endl;

    cout << getLengthLCS(str1.length(), str2.length()) << endl;

    return 0;
}
