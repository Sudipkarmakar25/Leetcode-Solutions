#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minSize=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            int g=strs[i].size();
            minSize=min(minSize,g);
        }
        string ans="";
        for(int i=0;i<minSize;i++)
        {
            set<char>st;
            for(int j=0;j<strs.size();j++)
            {
             st.insert(strs[j][i]);
            }
            if(st.size()==1)
            {
                ans+=strs[0][i];
            }
            else{
                break;
            }
            st.clear();
        }
        return ans;
    }
};