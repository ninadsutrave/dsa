#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

bool isCyclic(vector<int> adj[], int src, unordered_map<int,bool>& visited, vector<bool>& isOnStack) {

    visited[src] = true;
    isOnStack[src] = true;

    for(int neighbour: adj[src]) {
        if(isOnStack[neighbour]) return true;
        if(isCyclic(adj, neighbour, visited, isOnStack)) {
            return true;
        }
    }

    isOnStack[src] = false;
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

    unordered_map<int,bool> visited;
    for(int i = 0; i<V; ++i) {
        vector<bool> isOnStack(V, false);
        if(!visited[i]) {
            cyclic = cyclic | isCyclic(adj, i, visited, isOnStack);
        }
    }

    if(cyclic) cout<<"Cyclic";
    else cout<<"Not cyclic";

    return 0;
}

/**
 * Consider the following directed graph
 * 1 -> 0 <- 2 
 * 
 * If we follow the same approach as undirected graph cycle detection, 
 * it will fail here. First call to dfs will mark 0 as visited and the
 * function is complete because 0 has no neighbours
 * The next call to dfs will start at 1 and see that 0 is 1's neighbour
 * and is also visited and isn't 1's predecessor.
 * This was the condition of loop in undirected graph, which will fail here
 * 
 * Thus we need  additional space to rather store what is currently 
 * on the stack instead of storing what is already visited. This will
 * help us to identify cycles in directed graphs
 * 
 * Time Compleixity: O(V+E)
 * Space Complexity: O(V+E)
 * 
*/