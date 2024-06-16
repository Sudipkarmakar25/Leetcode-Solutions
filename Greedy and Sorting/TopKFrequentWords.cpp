#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparePairs(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first > b.first; 
        }
        return a.second < b.second; 
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        vector<pair<int, string>> req;
        for (const auto& x : freq) {
            req.push_back({x.second, x.first});
        }

        sort(req.begin(), req.end(), comparePairs); 

        vector<string> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(req[i].second);
        }

        return ans;
    }
};
