#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        vector<pair<int,int>>req;
        int n=difficulty.size();
        for(int i=0;i<n;i++)
        {
            req.push_back({difficulty[i],profit[i]});
        }
        sort(req.begin(),req.end());
        int ans=0;
        for(int i=0;i<worker.size();i++)
        {
            int maxi=0;
            for(int j=0;j<req.size();j++)
            {
             if(req[j].first>worker[i])
             {
                break;
             }
             maxi=max(maxi,req[j].second);
            }
            ans=ans+maxi;
        }
        return ans;
    }
};