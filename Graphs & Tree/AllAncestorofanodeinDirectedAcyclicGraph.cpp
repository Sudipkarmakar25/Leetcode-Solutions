#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v) { adjList[u].push_back(v); }

    void DFS(int node, unordered_map<int, bool>& visited, vector<int>& ancestors) {
        visited[node] = true;
        for (auto x : adjList[node]) {
            if (!visited[x]) {
                DFS(x, visited, ancestors);
            }
        }
        ancestors.push_back(node);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            addEdge(edges[i][0], edges[i][1]);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            unordered_map<int, bool> visited;
            vector<int> ancestors;
            DFS(i, visited, ancestors);
            for (int j = 0; j < n; j++) {
                if (i!= j && visited[j]) {
                    ans[j].push_back(i);
                }
            }
        }
        return ans;
    }
};