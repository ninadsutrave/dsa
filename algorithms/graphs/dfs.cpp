#include <iostream>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void dfs(vector<int> adj[], unordered_map<int,bool>& visited, int src) {

    cout<<src<<" ";
    visited[src] = true;

    for(int node: adj[src]) {
        if(!visited[node]) {
            dfs(adj, visited, node);
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

    unordered_map<int,bool> visited;
    for(int i = 0; i<V; ++i) {
        if(!visited[i]) {
            dfs(adj, visited, i);
        }
    }

    return 0;

}

/**
 * Time complexity: O(V+E)
 * Space complexity: O(V)
*/