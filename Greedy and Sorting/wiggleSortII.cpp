#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>req=nums;
        sort(req.begin(),req.end());
        int large=(nums.size()+1)/2;
        int small=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i%2==0){
            nums[i]=req[small];
            small++;
            }
            else{
                nums[i]=req[large];
                large++;
            }
        }
    }
};