#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>zero;
        int cnt=0;
        int one=0;
        zero.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) cnt++;
            else one++;
            zero.push_back(cnt);
        }
    int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int req1=0;
           if(i+one<nums.size())
           {
            ans=min(ans,zero[i+one]-zero[i]);
           }
           else{
             req1=zero[nums.size()]-zero[i];
             req1+=zero[one-nums.size()+i];
             ans=min(ans,req1);
           }
        }
       
        
        return ans;

    }
};