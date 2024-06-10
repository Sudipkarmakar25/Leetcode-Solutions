#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        vector<int> ans;
        unordered_map<char, int> run;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            run[s[i]]++;
            int chk = 0;
            cnt++;
            for (int j = 0; j <= i; j++) {
                if (run[s[j]] != freq[s[j]]) {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
       
        return ans;
    }
};