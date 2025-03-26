#include <iostream>
#include <vector>
#include <queue>
#define nl "\n"
#define sp " "

using namespace std;
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); 
}
void BFS(const vector<vector<int>>& adj, vector<bool>& visited, int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << sp;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
void BFSDisconnectedGraph(const vector<vector<int>>& adj, int vertices) {
    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            BFS(adj, visited, i);
            cout << nl;  
        }
    }
}

int main() {
    int vertices = 7; 
    vector<vector<int>> adj(vertices);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    cout << "BFS traversal of the disconnected graph:" <<nl;
    BFSDisconnectedGraph(adj, vertices);
    return 0;
}