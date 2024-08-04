#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> preSum(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        vector<int> all;
        for (int i = 0; i < n; i++) {
            all.push_back(preSum[i]);
            for (int j = 0; j < i; j++) {
                all.push_back(preSum[i] - preSum[j]);
            }
        }
        sort(all.begin(), all.end());
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = left - 1; i < right; i++) {
            ans = (ans % mod + all[i] % mod) % mod;
        }
        return ans;
    }
};