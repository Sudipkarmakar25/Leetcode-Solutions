#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        pq.push({0,{0,0}});

        dist[0][0]=0;
        while(!pq.empty())
        {
            auto fnode=pq.top();
            pq.pop();
            int d=fnode.first;
            int x=fnode.second.first;
             int y=fnode.second.second;
             if(x==heights.size()-1 && y== heights[0].size()-1)
             {
                return dist[x][y];
             }
             int dx[]={-1,0,1,0};
             int dy[]={0,1,0,-1};
             for(int i=0;i<4;i++)
             {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newy>=0 && newx<heights.size() && newy<heights[0].size())
                {
                    int currDiff=abs(heights[x][y]-heights[newx][newy]);
                    int newmax=max(currDiff,d);
                    if(newmax<dist[newx][newy])
                    {
                        dist[newx][newy]=newmax;
                        pq.push({newmax,{newx,newy}});
                    }
                }
             }
        }
        return 0;
    }
};