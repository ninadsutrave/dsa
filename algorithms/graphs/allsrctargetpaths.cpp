#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void getAllPaths(vector<int> adj[], vector<vector<int>>& allPaths, vector<bool>& visited, int src, vector<int> currPath, int target) {

    if(src == target) {
        allPaths.push_back(currPath);
        return;
    }

    visited[src] = true;

    for(int neighbour: adj[src]) {
        if(!visited[neighbour]) {
            currPath.push_back(neighbour);
            getAllPaths(adj, allPaths, visited, neighbour, currPath, target);
            currPath.pop_back();
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
    vector<int> path;
    vector<vector<int>> allPaths;
    path.push_back(src);
    getAllPaths(adj, allPaths, visited, src, path, target);

    for(vector<int> path: allPaths) {
        for(int node: path) {
            cout<<node<<" ";
        }
        cout<<"\n";
    }

    return 0;

}

/**
 * Time complexity: 
 * For dense graphs it is a time comsuming operation
 * 
 * Space complexity: O(V)
*/