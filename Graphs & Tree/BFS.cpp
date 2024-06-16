#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0) // Direction = 0 means this is an undirected graph
        {
            adjList[v].push_back(u);
        }
    }
    void BFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            cout << frontnode << " ";
            for (auto x : adjList[frontnode])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    unordered_map<int, bool> visited;
    g.BFS(0, visited);
    return 0;
}