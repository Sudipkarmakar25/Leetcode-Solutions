#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 1)
        {
            adjList[v].push_back(u);
        }
    }
    void topologicalsort(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {

        visited[src] = true;
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                topologicalsort(neighbour, visited, ans);
            }
        }
        ans.push(src);
    }
};
int main()
{
    graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 7, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 1);
    g.addEdge(8, 9, 1);
    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    g.topologicalsort(1, visited, topoOrder);
    while (!topoOrder.empty())
    {
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }

    return 0;
}