#include <vector>
#include <queue>
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

        pair<int,int> curr = pq.top();
        pq.top();



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