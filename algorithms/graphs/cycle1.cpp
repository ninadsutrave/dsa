#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclic(vector<int> adj[], int src, int pred, vector<bool>& visited) {

    visited[src] = true;

    for(int neighbour: adj[src]) {
        if(!visited[neighbour]) {
            if(isCyclic(adj, neighbour, src, visited)) {
                return true;
            }
        } else if(neighbour != pred) { // if visited already and it isnt the predecessor, it proves its a loop 
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

    bool cyclic = false;

    vector<bool> visited(V, false);
    for(int i = 0; i<V; ++i) {
        if(!visited[i]) {
            if(isCyclic(adj, i, -1, visited)) {
                cyclic = true;
                break;
            }
        }
    }

    if(cyclic) cout<<"Cyclic";
    else cout<<"Not cyclic";

    return 0;
}

/**
 * Time Complexity: O(V+E)
 * Space Complexity: O(V+E) adj list + visited array + call stack
 * 
 * If we are performing dfs on a graph, and the neighbour of a given node
 * is not its predecessor, but still is visited, it signifies a loop
 * 
 * So we will perform dfs and if this condition occurs we return true
*/