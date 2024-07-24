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
        int n=nums.size()-1;
          vector<int>dp(n+1,-1);
        return solve(nums,n,dp);
    }
};