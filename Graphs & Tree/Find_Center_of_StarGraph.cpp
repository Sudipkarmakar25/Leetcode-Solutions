#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>freq;
        for(int i=0;i<edges.size();i++)
        {
            freq[edges[i][0]]++;
            freq[edges[i][1]]++;
        }
        int ans;
        for(auto x:freq)
        {
            if(x.second==edges.size())
            {
                ans=x.first;
                break;
            }
        }
        return ans;
    }
};