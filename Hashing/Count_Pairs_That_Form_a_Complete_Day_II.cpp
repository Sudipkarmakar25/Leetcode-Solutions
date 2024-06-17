#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int, long long> rem;
        long long ans=0;
        for (int i : hours) {
            int k = (24 - i % 24) % 24;
            if (rem.find(k) != rem.end()) {
                ans += rem[k];
            }
            rem[i % 24]++;
        }
        return ans;
    }
};