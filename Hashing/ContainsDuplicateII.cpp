#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int,int>req;
      for(int i=0;i<nums.size();i++)
      {
        if(req.find(nums[i])==req.end())
        {
            req[nums[i]]=i;
        }
        else{
            cout<<abs(req[nums[i]]-i)<<endl;
            if(abs(req[nums[i]]-i)<=k) return true;
            else req[nums[i]]=i;
        }
      }
      return false;
    }
};