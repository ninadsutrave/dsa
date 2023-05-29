#include <iostream>
#include <queue>
using namespace std;

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
    cin>>V>>E;

    vector<int> adj[V];

    for(int i = 0; i<E; ++i) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    return 0;

}