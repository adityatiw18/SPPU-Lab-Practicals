
#include <bits/stdc++.h>
using namespace std;

// Memoisation (Top-Down)
int memo(int i, int W, vector<int>& wt, vector<int>& val,
         vector<vector<int>>& dp) {

    if (i == 0 || W == 0)
        return 0;

    if (dp[i][W] != -1)
        return dp[i][W];

    int notTake = memo(i - 1, W, wt, val, dp);

    int take = 0;
    if (wt[i - 1] <= W) {
        take = val[i - 1] +
               memo(i - 1, W - wt[i - 1], wt, val, dp);
    }

    return dp[i][W] = max(take, notTake);
}

// Tabulation (Bottom-Up)
int tabulation(int n, int W, vector<int>& wt, vector<int>& val) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    if (n <= 0 || W < 0) {
        cout << "Invalid input\n";
        return 0;
    }

    vector<int> wt(n), val(n);

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    int choice;
    cout << "\n1. Memoisation\n2. Tabulation\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        cout << "Maximum profit: "
             << memo(n, W, wt, val, dp);
    }
    else if (choice == 2) {
        cout << "Maximum profit: "
             << tabulation(n, W, wt, val);
    }
    else {
        cout << "Invalid choice";
    }

    return 0;
}
