#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
       int left=0;
       int right=height.size()-1;
       int area=0;
       while(left<right)
       {
            area=max(min(height[left],height[right])*(right-left),area);
           if(height[left]<height[right])
           {
               left++;
           }
           else{
               right--;
           }
       }
       return area;
    }
  
};