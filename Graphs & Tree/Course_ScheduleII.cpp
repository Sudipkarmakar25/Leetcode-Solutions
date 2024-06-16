#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void topologicalsort(int n, vector<int> &ans, unordered_map<int, list<int>> &adjList) {
        queue<int> q;
        unordered_map<int, int> indegree;
        for (auto i : adjList) {
            int src = i.first;
            for (auto nbr : i.second) {
                indegree[nbr]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto nbr : adjList[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        for (int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adjList[u].push_back(v);
        }

        vector<int> ans;
        vector<int> mt;
        topologicalsort(numCourses, ans, adjList);
     if(ans.size()!=numCourses)
     {
        return mt;
     }
        return ans;
    }
};
