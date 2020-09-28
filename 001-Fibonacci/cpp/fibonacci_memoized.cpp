#include<bits/stdc++.h>
using namespace std;

map<int, int> memo;

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
}

int main() {
    int n = 6;
    cout << "Calculating fibonacci of " << n << " using memo" << endl;
    cout << fibonacci(n) << endl;
    return 0;
}
