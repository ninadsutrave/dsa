#include <iostream>
#include <stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

bool isCyclic(vector<int> adj[], int src, vector<bool>& visited, vector<bool>& isOnStack) {

    visited[src] = true;
    isOnStack[src] = true;

    for(int neighbour: adj[src]) {
        if(isOnStack[neighbour]) return true;
        if(!visited[src] && isCyclic(adj, neighbour, visited, isOnStack)) {
            return true;
        }
    }

    isOnStack[src] = false;
    return false;

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

    bool isDAG = true; // run topological sort only if graph is directed acyclic

    vector<bool> visited(V, false);
    vector<bool> isOnStack(V, false);
    for(int i = 0; i<V; ++i) {
        for(int i = 0; i<V; ++i) {
            if(!visited[i]) {
                if(isCyclic(adj, i, visited, isOnStack)) {
                    isDAG = false;
                    break;
                }
            }
        }
    }

    if(isDAG) {
        visited.resize(V, false);
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
    } else {
        cout<<"Not a directed acyclic graph"<<"\n";
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
 * Intuition: 
 * It is basically a post order DFS algorithm. Once we reach a node,
 * we do not add it right away. Instead we first reach its children,
 * and add it at the last.
 * 
 * Applications:
 *  1. Given a list of tasks/courses, and their pre requisite tasks/courses
 *     find if it is possible to complete all tasks/courses
 *     (this can be done by checking if resulting graph is a DAG)
 *     The order in which they need to be executed is the topological sort
 * 
 *  2. Used in data serialisation
 *  3. Used to determine the order of compilation tasks to perform in makefiles
 *  4. Used to resolve symbol dependencies in linkers
*/