#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> &req, int k, vector<vector<int>> &ans, int index,int n) {
        if (k == 0) {
            ans.push_back(req);
            return;
        }
        if(index>=n)
        {
            return ;
        }
        req.push_back(index+1);
        solve(req, k - 1, ans, index + 1,n);
        req.pop_back();
        solve(req, k, ans, index + 1,n);
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>req;
       solve(req,k,ans,0,n);
       return ans;
    }
};