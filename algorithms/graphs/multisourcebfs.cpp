/* https://leetcode.com/problems/01-matrix/ */

#include <iostream>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void bfs(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0; i<n; ++i) {
        for(int j = 0; j<m; ++j) {
            if(matrix[i][j] == 0) {
                q.push({{i,j}, 0});
                visited[i][j] = true;
            }
        }
    }

    vector<vector<int>> dir { {0,1}, {0,-1}, {1,0}, {-1,0} };

    while(q.size()) {

        int row = q.front().first.first;
        int col = q.front().first.second; 
        int steps = q.front().second;
        q


    }

}

int main() {

    vector<vector<int>> matrix {
        {0,1,1,0},
        {1,1,1,1},
        {0,1,1,1},
        {1,1,1,0}
    };

    return 0;

}

/**
 * Time complexity: O(V+E)
 * Space complexity: O(V)
*/