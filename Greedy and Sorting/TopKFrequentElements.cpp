#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<pair<int,int>>req;
        for(auto x: freq)
        {
            req.push_back({x.second,x.first});
        }
        sort(req.rbegin(),req.rend());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(req[i].second);
        }
        return ans;
    }
};