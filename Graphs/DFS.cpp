#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, int direction)
    {
        adjList[u].push_back(v);
        if (direction == 0) // Direction=0 means this is an undirected graph
        {
            adjList[v].push_back(u);
        }
    }
    void DFS(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto x : adjList[src])
        {
            if (!visited[x])
            {
                DFS(x, visited);
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
    g.DFS(0, visited);
    return 0;
}