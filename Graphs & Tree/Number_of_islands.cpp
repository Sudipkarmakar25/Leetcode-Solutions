#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(pair<int,int>src,map<pair<int,int>,bool>&visited,vector<vector<char>>& grid) {
       if(grid[src.first][src.second]==0)
       {
        return;
       }
       queue<pair<int,int>>q;
       q.push(src);
       visited[src]=true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty())
        {
            auto frontnode=q.front();
            q.pop();

            for(auto dir :directions)
            {
                int newx=frontnode.first+dir[0];
                int newy=frontnode.second+dir[1];

                if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]==1 && !visited[{newx,newy}])
                {
                    q.push({newx,newy});
                    visited[{newx,newy}]=true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool>visited;
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
               pair<int,int> req={i,j};
               if(grid[i][j]==1 && !visited[req])
               {
                bfs(req,visited,grid);
                cnt++;
               }

            }
            
        }
        return cnt;
    }
};