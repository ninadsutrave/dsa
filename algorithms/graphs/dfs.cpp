#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void dfs(vector<int> adj[], vector<bool>& visited, int src) {
    cout<<src<<" ";
    visited[src] = true;

    for(int neighbour: adj[src]) {
        if(!visited[neighbour]) {
            dfs(adj, visited, neighbour);
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
            dfs(adj, visited, i);
        }
    }

    return 0;

}

/**
 * Applications:
 * • Used to find a path between two vertices
 * • Used to detect cycles in a graph
 * • Used in topological sorting
 * • Used to solve puzzles having only one solution (e.g., mazes)
 * 
 * Time complexity: O(V+E)
 * Space complexity: O(V)
*/