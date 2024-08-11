#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.rbegin(),arr.rend());
        unordered_map<int,int>freq;
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
       for(int i=0;i<arr.size();i++)
       {
        int first=arr[i];
        int second=2*arr[i];
        if(freq[first]>0 && freq[second]>0)
        {
            freq[first]--;
            freq[second]--;
        }
       }
        for(auto x: freq)
        {
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second>0) return false;
        }
        return true;
    }
};