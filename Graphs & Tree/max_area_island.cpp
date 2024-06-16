#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int bfs(pair<int,int>req,vector<vector<int>>& grid,map<pair<int,int>,bool>&visited,int &cnt)
{
queue<pair<int,int>>q;
q.push(req);
visited[req]=true;
 int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 cnt++;
 while(!q.empty())
 {
    auto frontnode = q.front();
            q.pop();

            for (auto dir : directions) {
                int newx = frontnode.first + dir[0];
                int newy = frontnode.second + dir[1];
                if (newx >= 0 && newx < grid.size() && newy >= 0 &&
                    newy < grid[frontnode.first].size() &&
                    grid[newx][newy]==1 && !visited[{newx, newy}]) {
                    q.push({newx, newy});
                    visited[{newx, newy}] = true;
                    cnt++;
                }
            }
 }
 return cnt;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        map<pair<int,int>,bool>visited;
       
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
              if(!visited[{i,j}] && grid[i][j]==1)
              {
                 int cnt=0;
                pair<int,int>req={i,j};
                int c=bfs(req,grid,visited,cnt);
                ans=max(ans,c);
              }
            }
        }
        return ans;
    }
};