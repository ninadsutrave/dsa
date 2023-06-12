/* https://leetcode.com/problems/01-matrix/ */

#include <iostream>
#include <queue>
using namespace std;

// returns a 2d matrix, with every cell value as distance of the nearest 0
vector<vector<int>> multisourceBFS(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0; i<n; ++i) {
        for(int j = 0; j<m; ++j) {
            if(matrix[i][j] == 0) {
                q.push({{i,j}, dist[i][j]});
                visited[i][j] = true;
            }
        }
    }

    vector<vector<int>> dir { {0,1}, {0,-1}, {1,0}, {-1,0} };

    while(q.size()) {

        int row = q.front().first.first;
        int col = q.front().first.second; 
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;

        for(vector<int> d: dir) {
            int new_row = row + d[0];
            int new_col = col + d[1];

            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !visited[new_row][new_col]) {
                visited[new_row][new_col] = true;
                q.push( {{ new_row, new_col }, steps+1} );
            }
        }

    }

    return dist;

}

int main() {

    vector<vector<int>> matrix {
        {0,1,1,0},
        {1,1,1,1},
        {0,1,1,1},
        {1,1,1,0}
    };

    vector<vector<int>> dist = multisourceBFS(matrix);

    return 0;

}

/**
 * Time complexity: O(N*M)
 * Space complexity: O(N*M)
 * 
 * Works by starting at every 0 as the source simutaneously
 * Marks all zeroes as distance 0 and moves 1 step from every source
 * Marks all these cells as distance 1 and continues similarly
 * Maintains a visited matrix to avoid loops
*/