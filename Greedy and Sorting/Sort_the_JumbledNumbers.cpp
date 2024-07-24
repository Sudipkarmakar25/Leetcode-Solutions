#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> req;
        for (int i = 0; i < nums.size(); i++) {
            int f = nums[i];
            if(f==0)
            {
                  req.push_back({mapping[0], i});
                  continue;
            }
            vector<int> ff;
            while (f > 0) {
                ff.push_back(f % 10);
                f /= 10;
            }
            reverse(ff.begin(), ff.end());
            int num = 0;
            for (auto x : ff) {
                num = num * 10 + mapping[x];
            }
            req.push_back({num, i});
            ff.clear();
        }
        sort(req.begin(),req.end());
        vector<int> ans;
        int mini = INT_MAX;

     for(auto x:req)
     { 
        cout<<nums[x.second]<<" "<<x.first<<endl;
        ans.push_back(nums[x.second]);
     }
        return ans;
    }
};