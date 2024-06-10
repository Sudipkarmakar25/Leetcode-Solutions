#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int ff = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] - ff) > k) {
                cnt++;
                ff = nums[i];
            }
        }
        return cnt + 1;
    }
};