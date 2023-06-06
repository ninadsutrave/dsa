#include <iostream>
#include <stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void sort(vector<int> adj[], vector<bool>& visited, int src, stack<int>& topologicalSort) {
    visited[src] = true;

    for(int node: adj[src]) {
        if(!visited[node]) {
            sort(adj, visited, node, topologicalSort);
        }
    }

    topologicalSort.push(src);
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

    vector<bool> visited(V, false);
    stack<int> topologicalSort;
    for(int i = 0; i<V; ++i) {
        if(!visited[i]) {
            sort(adj, visited, i, topologicalSort);
        }
    }

    while(topologicalSort.size()) {
        cout<<topologicalSort.top()<<" "; 
        topologicalSort.pop();
    }

    return 0;

}

/**
 * Time Complexity: O(V+E)
 * Space Complexity: O(V+E)
 * 
 * A linear ordering of nodes such that if an edge exists
 * from u to v, u occurs before v in the ordering.
 * 
 * It is valid only for directed acyclic graphs (DAG). If a 
 * cycle exists we won't be able to get a valid sort.
 * 
 * There can be multiple valid topological sorts.
 * 
 * Applications:
 *  1. Given a list of tasks/courses, and their pre requisite tasks/courses
 *     find if it is possible to complete all tasks/courses
 *     (this can be done by checking if resulting graph is a DAG)
 *     The order in which they need to be executed is the topological sort
*/