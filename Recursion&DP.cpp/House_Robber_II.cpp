#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(vector<int>&nums,int index,vector<int>&dp)
{
    if(index<0) return 0;
    if(index==0) return nums[0];
    if(dp[index]!=-1) return dp[index];
    int include=solve(nums,index-2,dp)+nums[index];
    int exclude=solve(nums,index-1,dp);
    dp[index]= max(include,exclude);
    return dp[index];
}
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==0) return 0;
        vector<int>first;
        vector<int>last;
        for(int i=0;i<nums.size()-1;i++)
        {
            first.push_back(nums[i]);
        }
         for(int i=1;i<nums.size();i++)
        {
            last.push_back(nums[i]);
        }
        vector<int>dp1(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        int ans=max(solve(first,first.size()-1,dp1),solve(last,last.size()-1,dp2));
        return ans;
    }
};