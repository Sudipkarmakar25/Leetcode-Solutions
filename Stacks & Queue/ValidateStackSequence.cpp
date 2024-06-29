#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int first=0;
        for(int i=0;i<pushed.size();i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[first])
            {
                s.pop();
                first++;
            }

        }
        if(s.size()==0) return true;
        else return false;
    }
};