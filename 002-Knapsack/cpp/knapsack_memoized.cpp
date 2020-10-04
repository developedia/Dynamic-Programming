#include<bits/stdc++.h>
using namespace std;

// value and weight array
int value[] = {5, 10, 25, 8, 20, 90, 3};
int weight[] = {10, 10, 25, 5, 5, 10, 1};

map<pair<int, int>, int> memo;

int knapsack(int n, int capacity) {
    // Base case
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // If already computed then return from memo
    else if (memo.find(make_pair(n, capacity)) != memo.end()) {
        return memo[make_pair(n, capacity)];
    }

    // When weight is more than capacity then skip
    else if (weight[n - 1] > capacity) {
        memo[make_pair(n, capacity)] = knapsack(n - 1, capacity);
        return memo[make_pair(n, capacity)];
    }

    // Return the maximum value either by skipping or by taking the n'th item
    else {
        memo[make_pair(n, capacity)] =  max(knapsack(n - 1, capacity),
            value[n - 1] + knapsack(n - 1, capacity - weight[n - 1]));
        return memo[make_pair(n, capacity)];
    }
}

int main() {

    // number of items
    int n = sizeof(value) / sizeof(int);

    // capacity of the knapsack
    int capacity = 25;

    cout << knapsack(n, capacity) << endl;

    return 0;
}
