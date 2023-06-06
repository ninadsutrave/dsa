#include <iostream>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void bfs(vector<int> adj[], int src, vector<bool>& visited) {

    queue<int> q;
    q.push(src);

    while(q.size()) {

        int node = q.front();
        q.pop();

        cout<<node<<" ";
        visited[node] = true;

        for(int neighbour: adj[node]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
            }
        }
    }

}

int main() {

    int V, E;
    int V = 5;

    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 5);

    vector<bool> visited(V, false);
    for(int i = 0; i<V; ++i) {
        if(!visited[i]) {
            bfs(adj, i, visited);
        }
    }

    return 0;

}

/**
 * Time complexity: O(V+E)
 * Space complexity: O(V)
*/