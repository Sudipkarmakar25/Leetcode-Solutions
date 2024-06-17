#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
       string s=to_string(x);
       int ptr1=0;
       int ptr2=s.size()-1;
       int chk=0;
       while(ptr2>ptr1)
       {
        if(s[ptr1]=='-')
        {
            ptr1++;
            continue;
        }
        if(s[ptr2]=='0'&&chk==0)
        {
            ptr2--;
            s.erase(s.begin()+ptr2+1);
            continue;
        }
        swap(s[ptr1],s[ptr2]);
        ptr1++;
        ptr2--;
        chk=1;
       }
       int ans;
       long long n=stoll(s);
       if(n>INT_MAX ||n<INT_MIN) return 0;
       else{
           ans=(int)n;
       }
       return ans; 
    }
};