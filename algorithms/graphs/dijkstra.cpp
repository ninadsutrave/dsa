#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

void addEdge(vector <pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
}

vector<int> dijkstras(vector<pair<int,int>> adj[], int V, int src) {

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

    vector<int> dist = dijkstras(adj,4,0);
    cout<<dist[1]<<"\n";
    cout<<dist[2]<<"\n";
    cout<<dist[3]<<"\n";

    return 0;
}

/**
 * Time Complexity: O((V + E) log V)
 * Space Complexity: O(V)
 * 
 * It is a greedy based approach as opposed to Bellman Ford 
 * algorithm which is based on dynamic programming.
 * 
 * Limitations:
 * • Does not work on graphs with negative weights/negative cycles
 * • Inefficient for dense graph (approaches)
 * • Cannot be applied in cases of obstacles on path or additional path constraints
 * 
 * Advantages:
 * • It is more efficient in case of positive weighted graphs 
 * • Bellman Ford has O(V.E) time complexity
 * 
 * Applications:
 * • Used to find directions to travel from one location to another in mapping 
 *   software like Google maps or Apple maps
 * • Used in networking to solve the min-delay path problem
 * • Used in abstract machines to determine the choices to reach a certain goal 
 *   state via transitioning among different states (e.g., can be used to 
 *   determine the minimum possible number of moves to win a game)
*/