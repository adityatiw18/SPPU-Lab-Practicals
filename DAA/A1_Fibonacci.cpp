#include <bits/stdc++.h>
using namespace std;

// Recursive Fibonacci
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Non-recursive (iterative) Fibonacci
long long fibIterative(int n) {
    if (n <= 1) return n;

    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n (0 to 45): ";
    cin >> n;

    if (n < 0 || n > 45) {
        cout << "Please enter n between 0 and 45.\n";
        return 0;
    }

    cout << "Fibonacci using recursion: " << fibRecursive(n) << '\n';
    cout << "Fibonacci using iteration: " << fibIterative(n) << '\n';

    return 0;
}
