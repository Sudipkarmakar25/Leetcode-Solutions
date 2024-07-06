#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==1)
            {
                ans+=nums[i];
            }
        }
        return ans;
    }
};