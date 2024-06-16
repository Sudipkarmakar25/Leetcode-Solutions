#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long DFS(long long src, unordered_map<long long, bool>& visited,
                  long long& cnt,
                  unordered_map<long long, list<long long>>& adjList) {

        visited[src] = true;
        cnt++;
        for (auto x : adjList[src]) {
            if (!visited[x]) {
                DFS(x, visited, cnt, adjList);
            }
        }
        return cnt;
    }

    long long countPairs(long long n, vector<vector<int>>& edges) {
        unordered_map<long long, list<long long>> adjList;
        for (long long i = 0; i < edges.size(); i++) {
            long long u = edges[i][0];
            long long v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        unordered_map<long long, bool> visited;
        vector<long long> num;
        long long cnt = 0;
        for (long long i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt = 0;
                long long c = DFS(i, visited, cnt, adjList);
                num.push_back(c);
            }
        }
        long long ans = (n * (n - 1)) / 2;
        for (long long c : num) {
            ans -= (c * (c - 1)) / 2;
        }
        return ans;
    }
};