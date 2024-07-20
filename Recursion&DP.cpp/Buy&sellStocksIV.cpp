#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp,
              int limit) {
        if (index == prices.size()) {
            return 0;
        }
        if (limit == 0) {
            return 0;
        }
        if (dp[index][buy][limit] != -1) {
            return dp[index][buy][limit];
        }
        int profit = 0;
        if (buy) {
            profit = max(
                (-1 * prices[index] + solve(index + 1, 0, prices, dp, limit)),
                (0 + solve(index + 1, 1, prices, dp, limit)));
        } else {
            profit = max(
                (prices[index] + solve(index + 1, 1, prices, dp, limit - 1)),
                (0 + solve(index + 1, 0, prices, dp, limit)));
        }
        dp[index][buy][limit] = profit;
        return profit;
    }
    
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+2, -1)));
        int limit = k;
        return solve(0, 1, prices, dp, limit);
    }
};