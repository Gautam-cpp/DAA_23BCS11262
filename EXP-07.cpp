
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i - 1] <= w)
                    dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                else
                    dp[i][w] = dp[i - 1][w];
            }
        }
        return dp[n][W];
    }
};

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    Solution s;
    int result = s.knapsack(W, val, wt);

    cout << "Maximum value in knapsack = " << result << endl;
    return 0;
}
