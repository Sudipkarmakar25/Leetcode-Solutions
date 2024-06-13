#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<vector<int>>& ans, vector<int> req) {
        if (target == 0) {
            ans.push_back(req);
            return;
        }
        if (index >= candidates.size() || target<0) {
            return;
        }
        solve(candidates, target,index + 1, ans, req); 

        req.push_back(candidates[index]);
        solve(candidates, target- candidates[index], index, ans, req);
        req.pop_back();
        
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> req;
        int sum = 0;
        vector<vector<int>> ans;
        solve(candidates, target, 0, ans, req);
        return ans;
    }
};
