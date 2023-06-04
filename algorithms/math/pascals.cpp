#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> pascals(int n) {

    vector<vector<int>> nCk{31, vector<int>(31,-1)};        
    vector<vector<int>> pascal;        
        
    for(int i = 0; i<n; ++i) {            
                        
        vector<int> row;            
        for(int j = 0; j<=i; ++j) {
                
            if(j == 0 || j == i)
                nCk[i][j] = 1;
            else
                nCk[i][j] = nCk[i-1][j-1] + nCk[i-1][j];
                row.push_back(nCk[i][j]);                
        }
            
        pascal.push_back(row);
            
    }
        
    return pascal;

}

int main() {

    vector<vector<int>> result;
    result = pascals(10);

    for(vector<int> row: result) {
        for(int value: row) {
            cout<< value << " ";
        }
        cout<<"\n";
    }

    return 0;

}

/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * 
 * Utilising the recursive nature of binomial coefficient
 * C(n,k) = C(n-1,k-1) + C(n-1,k)
*/