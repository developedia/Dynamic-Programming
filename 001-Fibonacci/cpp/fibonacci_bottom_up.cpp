#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    // Create an array of size n + 1
    int *result = new int[n + 1];

    // Fill the base cases
    result[0] = 1;
    result[1] = 1;

    // Iterate till n
    for (int i = 2; i <= n; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }

    // Return fibonacci(n)
    return result[n];
}

int main() {
    int n = 6;
    cout << "Calculating fibonacci of " << n << " bottom-up" << endl;
    cout << fibonacci(n) << endl;
    return 0;
}
