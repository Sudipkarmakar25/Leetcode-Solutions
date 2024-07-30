#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
       int arr[n];
       int brr[n];
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
             brr[i]=cnt;
             if(s[i]=='b') cnt++;
        }
        cnt=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            arr[i]=cnt;
            if(s[i]=='a') cnt++;
            
        }
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++)
        {  
         ans=min(ans,(arr[i]+brr[i]));
        }
        return ans;
    }
};