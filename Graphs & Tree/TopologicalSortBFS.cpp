#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }
    void topologicalsort(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;
        // Indegree Calculation
        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // Put all Nodesinside queue which has indegree 0
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto nbr : adjList[front])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
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
    vector<int> ans;
    g.topologicalsort(9, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}