#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(right>left)
        {
            if(s[left]>=s[right])
            {
                s[left]=s[right];
            }
            else{
                s[right]=s[left];
            }
            left++;
            right--;
        }
        return s;
    }
};