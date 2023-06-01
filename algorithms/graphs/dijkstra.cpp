#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void addEdge(vector <pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
}

void dijkstras(vector<pair<int,int>> adj[], int V, int src) {

    priority_queue<pair<int,int>> pq;
    vector<bool> visited(V, false);
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(pq.size()) {

        int curr = pq.top().second;
        pq.pop();

        if(visited[curr]) continue;

        visited[curr] = true;

        for(pair<int,int> node: adj[curr]) {
            // weight of path from src to node -> node.second
            if(dist[curr]+node.second < dist[node.first]) {
                dist[node.first] = dist[curr]+node.second;
                pq.push(make_pair(dist[node.first], node.first));
            }
        }

    }


}

int main()
{
    int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);

    return 0;
}