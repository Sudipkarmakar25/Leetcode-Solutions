#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i <46341; i++) {
            double b = sqrt(c - pow(i, 2));
            if(ceil(b)==floor(b)) return true;
        }
        return false;
    }
};