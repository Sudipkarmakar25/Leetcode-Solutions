#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation=0;
        int mini=nums[0];
        for(int i=1;i<nums.size();i++)
        {
          if(nums[i]>mini)
          {
            mini=nums[i];
          }
          else{
            operation+=(mini-nums[i]+1);
            nums[i]=mini+1;
            mini=nums[i];
          }
        }
        return operation;
    }
};