#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
     int n=arr.size();
     int presum[n];
     presum[0]=(arr[0]);
     for(int i=1;i<arr.size();i++)
     {
     presum[i]=presum[i-1]+arr[i];
     } 
     int odd=0;
     int even=0;
     int ans=0;
     for(int i=0;i<n;i++)
     {
        if(presum[i]%2==0)
        {
        ans=(ans%mod+odd%mod)%mod;
        even++;
        }
        else{
            ans=(ans%mod+(even%mod+1%mod)%mod)%mod;
            odd++;
        }
     }
     return ans;  
    }
};