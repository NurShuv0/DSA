#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#define sp " "
#define nl "\n"
#define V 8

using namespace std;
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}
int fordFulkerson(int graph[V][V], int s, int t)
{
    int rGraph[V][V];
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int graph[V][V] = {
        {0, 13, 10, 10, 0, 0, 0, 0},
        {0, 0, 0, 0, 24, 0, 0, 0},
        {0, 5, 0, 15, 0, 0, 7, 0},
        {0, 0, 0, 0, 0, 0, 15, 0},
        {0, 0, 0, 0, 0, 1, 0, 9},
        {0, 0, 0, 0, 0, 0, 6, 13},
        {0, 0, 0, 0, 0, 0, 0, 16},
        {0, 0, 0, 0, 0, 0, 0, 0}};

    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 7) << nl;
}
