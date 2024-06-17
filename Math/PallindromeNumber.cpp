#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int>n;
      while(x>0)
      {
        n.push_back(x%10);
        x=x/10;
      }
      int chk=0;
      int i=0;
      int j=n.size()-1;
      while(i<j)
      {
          if(n[i]!=n[j])
          {
              chk=1;
              break;
          }
          i++;
          j--;
      }
    if(chk==1) return false;
    else return true;
    }
};