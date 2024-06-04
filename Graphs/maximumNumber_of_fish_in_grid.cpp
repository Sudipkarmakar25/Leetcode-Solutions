#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(pair<int, int> req, map<pair<int, int>, bool>& visited,
             vector<vector<int>>& grid, int& maxi) {
        queue<pair<int, int>> q;
        q.push(req);
        visited[req] = true;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        maxi += grid[req.first][req.second];
        while (!q.empty()) {
            auto frontnode = q.front();
            q.pop();

            for (auto dir : directions) {
                int newx = frontnode.first + dir[0];
                int newy = frontnode.second + dir[1];
                if (newx >= 0 && newx < grid.size() && newy >= 0 &&
                    newy < grid[frontnode.first].size() &&
                    grid[newx][newy] >0 && !visited[{newx, newy}]) {
                    q.push({newx, newy});
                    maxi = maxi + grid[newx][newy];
                    visited[{newx, newy}] = true;
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        map<pair<int, int>, bool> visited;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                pair<int, int> req = {i, j};
                if (grid[i][j] > 0 && !visited[{i, j}]) {
                    int maxi = 0;
                    bfs(req, visited, grid, maxi);
                    ans = max(ans, maxi);
                }
            }
        }
        return ans;
    }
};