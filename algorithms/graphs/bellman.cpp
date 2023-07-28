#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void addEdge(vector <pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
}

vector<int> bellmanFord(vector<pair<int,int>> adj[], int V, int src) {

    priority_queue<pair<int,int>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push(make_pair(dist[src], src));

    while(pq.size()) {

        int curr = pq.top().second;
        pq.pop();

        for(pair<int,int> node: adj[curr]) {
            // node->second - weight of path from src to node
            if(dist[curr]+node.second < dist[node.first]) {
                dist[node.first] = dist[curr]+node.second;
                pq.push(make_pair(dist[node.first], node.first));
            }
        }
    }

    return dist;
}

int main() {

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

/**
 * Bellman Ford is a dynamic programming based approach whereas 
 * Dijkstras is a greedy approach
 * 
 * The ith iteration guarantees to give all shortest paths which are at most i edges long
 * 
 * Applications:
 * • Used to find directions to travel from one location to another in mapping 
 *   software like Google maps or Apple maps
 * • Used in networking to solve the min-delay path problem
 * • Used in abstract machines to determine the choices to reach a certain goal 
 *   state via transitioning among different states (e.g., can be used to 
 *   determine the minimum possible number of moves to win a game)
 * 
*/