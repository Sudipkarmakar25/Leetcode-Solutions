#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            else{
                if(!st.empty())
                {
                char tooop=st.top();
                if(tooop== '(' && ch==')')
                {
                    st.pop();
                }
                else if(tooop== '{' && ch=='}')
                {
                     st.pop();
                }
                else if(tooop== '[' && ch==']')
                {
                     st.pop();
                }
                else{
                    return false;
                }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
       
    }
};