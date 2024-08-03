#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>freq;
        set<int>req;
        for(int i=0;i<target.size();i++)
        {
            freq[target[i]]++;
            req.insert(target[i]);
        }
        unordered_map<int,int>freq2;
        for(auto x: arr)
        {
          freq2[x]++;
          req.insert(x);
        }
        if(freq.size()!=freq2.size()) return false;
        for(auto x:req)
        {
            if(freq[x]!=freq2[x]) return false;
        }
        return true;
    }
};