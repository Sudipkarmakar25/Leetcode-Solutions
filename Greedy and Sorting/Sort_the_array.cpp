#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};