#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <exception>
#include <queue>
using namespace std;

class Graph {

    private:
    unordered_map<int, unordered_set< pair<int,int> >> adj;
    bool isDirected;
    bool hasNegativeEdge;

    void dfsHelper(int src, unordered_map<int,bool>& visited, vector<int>& traversal) {
        traversal.push_back(src);
        visited[src] = true;
        for(pair<int,int> neighbour: adj[src]) {
            if(!visited[neighbour.first]) {
                dfsHelper(neighbour.first, visited, traversal);
            }
        }
    }

    void bfsHelper(int src, unordered_map<int,bool>& visited, vector<int>& traversal) {
        queue<int> q;
        q.push(src);
        while(q.size()) {
            int node = q.front();
            q.pop();
            traversal.push_back(node);
            for(pair<int,int> neighbour: adj[src]) {
                if(!visited[neighbour.first]) {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true; 
                    // important - mark visited while pushing, not while popping
                }
            }
        }
    }

    void shortestPathHelper(int src, int dest, vector<int>& shortestPath)  {

        if(hasNegativeEdge) {

        } else {
            priority_queue<pair<int,int>> pq;
            unordered_map<int,int> dist;

            for(auto [node, neighbour]: adj) {
                dist[node] = INT_MAX;
            }

            dist[src] = 0;
            pq.push({dist[src], src});

            while(pq.size()) {
                int node = pq.top().second;
                int distSoFar = pq.top().first;
                pq.pop();
                for(pair<int,int> neighbour: adj[node]) {
                    if(dist[neighbour.first] > neighbour.second + distSoFar) {
                        dist[neighbour.first] = neighbour.second + distSoFar;
                        pq.push({dist[neighbour.first], neighbour.first});
                    }
                }
            }
        }

    }   

    public:
    Graph(bool isDirected) {
        this->isDirected = isDirected;
        hasNegativeEdge = false;
    }

    void addEdge(int u, int v, int weight) {

        if(weight<0) hasNegativeEdge = true;

        adj[u].insert({v,weight});
        if(!isDirected) {
            adj[v].insert({u,weight});
        }
    }

    vector<int> getDfs(int src) {

        vector<int> traversal;
        unordered_map<int,bool> visited;
        dfsHelper(src, visited, traversal);
        return traversal;

    }

    vector<int> getBfs(int src) {

        vector<int> traversal;
        unordered_map<int,bool> visited;
        bfsHelper(src, visited, traversal);
        return traversal;

    }

    vector<int> getShortestPath(int src, int dest) {

        vector<int> shortestPath;
        shortestPathHelper(src, dest, shortestPath);
        return shortestPath;

    }
};

int main() {

    return 0;
}