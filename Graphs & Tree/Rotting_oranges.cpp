#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited=grid;
        queue<pair<int,int>>q;
        int countFresh=0;
        int minutes=-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(visited[i][j]==1)
                {
                    countFresh++;
                }
            }
        }
        if(countFresh==0) return 0;
        if(q.empty()) return -1;
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x,y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        countFresh--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        
        if (countFresh == 0)
            return minutes;
        return -1;


    }
};