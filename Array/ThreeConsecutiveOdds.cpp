#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%2!=0) cnt++;
            else cnt=0;
            if(cnt==3)
            {
                return true;
            }
        }
        return false;
    }
};