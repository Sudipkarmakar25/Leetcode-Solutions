#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void bfs(int src, unordered_map<int, bool> &visited, vector<vector<int>> adjacencyList)
    {
        queue<int> q;

        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            int frontnode = q.front();
            q.pop();

            for (auto neighbour : adjacencyList[frontnode]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isConnected[i][j] != 0 && i != j)
                {
                    adjacencyList[i].push_back(j);
                }
            }
        }

        unordered_map<int, bool> visited;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(i, visited, adjacencyList);
                cnt++;
            }
        }
        return cnt;
    }
};