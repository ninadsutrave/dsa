#include <algorithm>
#include <exception>
#include <iostream>
using namespace std;

long long int binomialCoefficient(int n, int k) {

    /**
     * space and time efficient method
     * 
     * nCk = n!/k!(n-k)! = n(n-1)(n-2)...(n-k+1)/1.2.3...(k-1)k
     * Numerator   =  n(n-1)(n-2)...(n-k+1)  =  product(n-i+1)
     * Denominator =  1.2.3.4.......(k-1)k   =  product(i)
    */

    if (n < 0 || k < 0) {
        throw invalid_argument("n and k must be non negative");
    }

    if(k>n) return 0;

    k = min(k, n-k);
    long long int result = 1;

    for (int i = 1; i <= k; ++i) {
        result = result*(n - i + 1);
        result = result/(i);
    }

    return result;

}

long long int nCk(int n, int k) {

    // C(n,k) = C(n-1,k-1) + C(n-1,k)
    // preferable if we have large queries for nCk 
    // (such as for printing pascals triangle)

    vector<vector<int>> nCk{31, vector<int>(31,-1)};        
    vector<vector<int>> pascal;        
        
    for(int i = 0; i<n; ++i) {            
         
        for(int j = 0; j<=i; ++j) {
                
            if(j == 0 || j == i) {
                nCk[i][j] = 1;
            }
            else {
                nCk[i][j] = nCk[i-1][j-1] + nCk[i-1][j];   
            }          
        }
            
    }
        
    return nCk[n][k];

}

int main() {

    cout<< binomialCoefficient(10,3) << "\n";
    cout<< nCk(6,5) << "\n";

    return 0;

}

/**
 * 
 * Time Complexity: (O(min(k, n-k)))
 * Space Complexity: O(1)
 * Binomial coefficients are used in combinatorics to calculate
 * the number of ways of picking k items from a group of n items
 * 
*/