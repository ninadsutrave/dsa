#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(vector<int> adj[], int src, int pred, unordered_map<int,bool>& visited) {

    visited[src] = true;

    for(int neighbour: adj[src]) {
        if(!visited[neighbour]) {
            if(dfs(adj, neighbour, src, visited)) {
                return true;
            }
        } else if(neighbour != pred) {
            return true;
        }
    }

    return false;

}

int main() {

    int V;
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
            dfs(adj, i, -1, visited);
        }
    }

    return 0;
}

/**
 * Time Complexity: O(V+E)
 * Space Complexity: O(V+E) adj list + visited array + call stack
*/