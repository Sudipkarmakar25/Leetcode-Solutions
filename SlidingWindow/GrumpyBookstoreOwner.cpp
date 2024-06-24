#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i]==0)
            {
                s=s+customers[i];
            }
        }
        int ff=0;
        int ll=minutes;
        int ans=s;
        while(ll<=grumpy.size())
        {
            int ss=s;
            cout<<ss<<endl;
            for(int i=ff;i<ll;i++)
            {
                if(grumpy[i]==1)
                {
                    ss+=customers[i];
                }
            }
            ff++;
            ll++;
            ans=max(ans,ss);
        }
     return ans;
    }
};