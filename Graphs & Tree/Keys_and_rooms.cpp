#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, bool> visited(rooms.size());
        queue<int> q;
        visited[0] = true;
        for (int i = 0; i < rooms[0].size(); i++) {
            if (!visited[rooms[0][i]]) {
                q.push(rooms[0][i]);
                visited[rooms[0][i]] = true;
            }
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int i = 0; i < rooms[f].size(); i++) {
                if (!visited[rooms[f][i]]) {
                    q.push(rooms[f][i]);
                    visited[rooms[f][i]] = true;
                }
            }
        }
        if (visited.size() == rooms.size())
            return true;
        else
            return false;
    }
};