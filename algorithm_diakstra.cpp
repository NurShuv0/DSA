#include <iostream>
#include <climits>

using namespace std;

#define V 6

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t\t\t" << dist[i] << "\n";
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 5, 3, 0, 0, 0},
        {5, 0, 1, 2, 0, 0},
        {3, 1, 0, 4, 0, 0},
        {0, 2, 4, 0, 2, 0},
        {0, 0, 0, 2, 0, 6},
        {0, 0, 0, 0, 6, 0}};

    int src = 0;
    dijkstra(graph, src);

    return 0;
}
