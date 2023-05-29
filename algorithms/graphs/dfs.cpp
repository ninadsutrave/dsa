#include <iostream>
using namespace std;

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
    cin>>V>>E;

    vector<int> adj[V];

    for(int i = 0; i<E; ++i) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    for(int i = 0; i<V; ++i) {
        if(!visited[i]) {
            dfs(adj, visited, i);
        }
    }

    return 0;

}