#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push('(');
            else {
                if (!st.empty()) {
                    st.pop();
                } else {
                    open++;
                }
            }
        }
        return (open+st.size());
    }
};