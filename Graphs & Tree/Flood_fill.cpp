#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,
             map<pair<int, int>, bool>& visited, vector<vector<int>>& ans) {
        visited[{sr, sc}] = true;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        ans[sr][sc] = color;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto frontnode = q.front();
            q.pop();

            for (auto dir : directions) {
                int newx = frontnode.first + dir[0];
                int newy = frontnode.second + dir[1];

                if (newx >= 0 && newx < image.size() && newy >= 0 &&
                    newy < image[0].size() &&
                    image[newx][newy] == image[sr][sc] &&
                    !visited[{newx, newy}]) {
                    ans[newx][newy] = color;
                    q.push({newx, newy});
                    visited[{newx, newy}] = true;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int ini = image[sr][sc];
        map<pair<int, int>, bool> visited;
        bfs(image, sr, sc, color, visited, ans);
        return ans;
    }
};