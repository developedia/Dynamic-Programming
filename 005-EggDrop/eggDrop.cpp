#include <bits/stdc++.h>

using namespace std;

// Memo to store previously calculated min drops
unordered_map<string, int> memo;

// Method to build key
string getKey(int int1, int int2) {
    return to_string(int1) + " " + to_string(int2);
}

// Method to calculate min drops required
int getMinEggDrops(int eggs, int floors) {
    // Base case
    if (eggs == 1 || floors == 0 || floors == 1) return floors;

    // Check in memo
    string key = getKey(eggs, floors);
    if (memo.find(key) != memo.end()) return memo[key];

    // Compute, store in memo, and return
    memo[key] = INT_MAX;
    for (int floor = 1; floor <= floors; floor++) {
        memo[key] = min(memo[key], 1 + max(getMinEggDrops(eggs - 1, floor - 1), getMinEggDrops(eggs, floors - floor)));
    }
    return memo[key];
}

int main() {
    int eggs = 3, floors = 15;
    cout << getMinEggDrops(eggs, floors) << endl;

    return 0;
}
