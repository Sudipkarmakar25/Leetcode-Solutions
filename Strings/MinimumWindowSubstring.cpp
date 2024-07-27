#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(256, 0);
        for (char c : t) {
            map[c]++;
        }

        int first = 0, last = 0, count = t.size();
        int minLength = INT_MAX, startingIndex = -1;

        while (last < s.size()) {
            if (map[s[last]] > 0) {
                count--;
            }
            map[s[last]]--;
            last++;

            while (count == 0) {
                if (last - first < minLength) {
                    minLength = last - first;
                    startingIndex = first;
                }
                map[s[first]]++;
                if (map[s[first]] > 0) {
                    count++;
                }
                first++;
            }
        }

        if (startingIndex == -1) {
            return "";
        } else {
            return s.substr(startingIndex, minLength);
        }
    }
};
