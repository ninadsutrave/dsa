#include <algorithm>
#include <exception>
#include <iostream>
using namespace std;

long long int binomialCoefficient(int n, int k) {

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

long long int catalan(int n) {

    vector<long long int> catalan(n+1);
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; ++i) {
        catalan[i] = 0;
        for (int j = 0; j < i; ++j) {
            catalan[i] = catalan[i] + (catalan[j] * catalan[i - j - 1]);
        }
    }

    return catalan[n];
}

int main() {

    int n = 15;

    cout<<binomialCoefficient(2*n, n)/(n+1)<<"\n";
    cout<<catalan(n)<<"\n";


    return 0;
}

/**
 * Catalan Numbers
 * 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  
 * 
 * Cn = (2n)!/n!(n+1)! = C(2n,n)/(n+1) -> (binomial coefficient)
 * 
 * C0 = 1
 * Cn+1 = sum(Ci * Cn-i)
 * 
 * Applications:
 *  1. Number of possible binary search trees with n keys
 *  2. Number of balanced expressions containing n pairs of parantheses
 *     ((())), ()(()), ()()(), (())(), (()())
 *  3. Number of full binary trees with n nodes
 *  4. Number of binary strings such that no inital segment of string contains more 0s than 1s (Dyck words)
 *  5. Number of paths with 2n steps on a rectangular grid from bottom left that
 *     do not cross above the main diagonal
 *  6. Number of ways a convex polygon of n+2 sides can split into triangles by connecting vertices
 *  7. Number of mountain ranges with peaks and valleys such that range stays above the land
 * 
 *                                    /\
 *                /\   /\     /\/\   / \
 *     /\/\/\  /\/ \  / \/\  /   \  /  \
*/