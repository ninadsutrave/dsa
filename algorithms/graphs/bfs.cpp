#include <iostream>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void bfs(vector<int> adj[], int src, unordered_map<int,bool>& visited) {

    queue<int> q;
    q.push(src);

    while(q.size()) {
        if(!visited[src]) {
            
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

    return 0;

}

/**
 * Time complexity: O(V+E)
 * Space complexity: O(V)
*/