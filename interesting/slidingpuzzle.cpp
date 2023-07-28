/* https://leetcode.com/problems/sliding-puzzle/ */
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> getSolvedPosition(int rows , int cols) {
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    int count = 1;

    for(int i = 0; i<rows; ++i) {
        for(int j = 0; j<cols; ++j) {
            result[i][j] = count++;
        }
    }

    result[rows-1][cols-1] = 0;
    return result;
}

void getZero(vector<vector<int>>& board, int& x_, int& y_) {

    int rows = board.size();
    int cols = board[0].size();

    for(int i = 0; i<rows; ++i) {
        for(int j = 0; j<cols; ++j) {
            if(board[i][j] == 0) {
                x_ = i;
                y_ = j;
                break;
            }
        }
    }
}

bool isValid(int rows, int cols, int x, int y) {
    return (x>=0 && x<rows && y>=0 && y<cols);
}

int solveSlidingPuzzle(vector<vector<int>>& board) {
        
    int rows = board.size();
    int cols = board[0].size();

    queue< pair< vector<vector<int>>, int> > q;
    q.push({board, 0}); // initial state has zero steps
    map< vector<vector<int>>, bool > visited;

    vector<vector<int>> result = getSolvedPosition(rows, cols);

    while(q.size()) {

        vector<vector<int>> curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(curr == result) {
            return steps;
        }

        visited[curr] = true;

        int x_, y_;
        getZero(curr, x_, y_);         

        vector<vector<int>> dir {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(vector<int> d: dir) {
            int new_x = x_ + d[0];
            int new_y = y_ + d[1];

            if(isValid(rows, cols, new_x, new_y)) {
                swap(curr[x_][y_], curr[new_x][new_y]);
                if(!visited[curr]) {
                    q.push({curr, steps+1});
                }
                swap(curr[x_][y_], curr[new_x][new_y]);
            }
        }

    }

    return -1;

}

int main() {

    vector<vector<int>> board1 {
        {4,1,2},
        {5,0,3}
    };

    vector<vector<int>> board2 {
        {6,1,3},
        {5,4,8},
        {0,7,2}
    };

    cout<<solveSlidingPuzzle(board1)<<"\n";
    cout<<solveSlidingPuzzle(board2)<<"\n";

    return 0;
}

/**
 * 
 * Given a board of n*m dimensions, there are (n*m)! possible game states.
 * So for a given 2*3 grid, there are only 720 possible game states
 * 
 * Thus we can essentially perform a bfs, traversing to every possible game
 * states, keeping a track of the number of steps taken to reach there, and
 * the visited game states
 * 
 * If the game state reaches its solved state, we return the number of steps
 * taken, or if the bfs is exhausted, we claim that it is impossible to solve
 * the possible with the given configuraition.
 * 
*/