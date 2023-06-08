#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void getAllPaths(vector<int> adj[], vector<bool>& visited, int src, string path, int target) {

    if(src == target) {
        cout<<path<<"\n";
        return;
    }

    visited[src] = true;

    for(int neighbour: adj[src]) {
        if(!visited[neighbour]) {
            path = path + to_string(neighbour);
            getAllPaths(adj, visited, neighbour, path, target);
            path.pop_back();
            visited[neighbour] = false;
        }
    }
}

int main() {

    int V, E;
    V = 6;

    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 2);

    int src = 0;
    int target = 5;
 
    vector<bool> visited(V, false);
    string currPath = to_string(src);
    getAllPaths(adj, visited, src, currPath, target);

    return 0;

}

/**
 * Time complexity: O(V^V)
 * For dense graphs it is a time comsuming operation
 * 
 * Space complexity: O(V)
*/