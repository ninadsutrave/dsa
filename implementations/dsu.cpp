#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion {

    private:
    vector<int> parent;
    vector<int> rank;

    public:
    DisjointSetUnion(size_t size) {
        parent.resize(size);
        for(int i = 0; i<size; ++i) {
            parent[i] = i;
        }
        rank.resize(size, 0);
    }

    ~DisjointSetUnion() {

    }

    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionNodes(int u, int v) {
        
        u = findParent(u);
        v = findParent(v);

        if(u == v) return;

        if(rank[u]<rank[v]) {
            parent[u] = v;
        } else if(rank[u]>rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            ++rank[u];
        }

    }
};

int main() {

    DisjointSetUnion dsu(10);

    dsu.unionNodes(0, 1);
    dsu.unionNodes(2, 3);
    dsu.unionNodes(4, 5);
    dsu.unionNodes(6, 7);
    dsu.unionNodes(8, 9);

    cout<<"Parent of 1: "<<dsu.findParent(1)<<"\n";
    cout<<"Parent of 4: "<<dsu.findParent(4)<<"\n";
    cout<<"Parent of 7: "<<dsu.findParent(7)<<"\n";

    dsu.unionNodes(1, 3);
    dsu.unionNodes(5, 7);
    dsu.unionNodes(2, 9);

    cout<<"Parent of 3: "<<dsu.findParent(3)<<"\n";
    cout<<"Parent of 7: "<<dsu.findParent(7)<<"\n";
    cout<<"Parent of 9: "<<dsu.findParent(9)<<"\n";

    return 0;
}

/**
 * Disjoint-Set data structure, also termed as the union-find data structure is a 
 * data structure which keeps track of elements partitioned in non overlapping subsets 
 * Major applications:
 * Counting connected components in a graph/matrix
 * Cycle detection in a graph as in Kruskal's algorithm
 * 
 * We use two very important optimisations in our implementation - 
 *  Union by Rank      (maintaining rank matrix and strategically merging the trees)
 *  Path Compression   (updating the parent of node after one query)
 * 
 * DSU with union by size / rank, but without path compression works in  O(log n) time per query
 * Also, in our case a single call might take  O(log n) in the worst case, but if we do m 
 * such calls back to back we will end up with an average time of O(α(n)) 
 * 
 * find():    
 * Amortised time complexity - O(α(n))
 * 
 * union():
 * Amortised time complexity - O(α(n))
 * 
 * α(n) - Inverse Ackermann function
 * 
 * Inverse Ackermann function, α(n), is an extremely slowly growing function and is considered a theoretical bound.
 * Actual time complexities of find and unite operations in DSU are effectively constant, making them highly efficient 
 * for most use cases. It is an extremely slowly growing function that approaches infinity, but it grows so slowly that 
 * it can be treated as a constant for all practical purposes.
 * 
 * Ackerman Function:
 * 
 * A(m, n)  =  n + 1                    m = 0
 *          =  A(m - 1, 1)              m > 0 and n = 0
 *          =  A(m - 1, A(m, n - 1))    m > 0 and n > 0
 * 
 * Inverse Ackerman Function:
 * α(n) = min{k ≥ 0 : A(k, k) > n}
 * 
 * In simpler terms, the inverse Ackermann function α(n) represents the minimum value of k 
 * for which the Ackermann function A(k, k) exceeds the input value n.
*/