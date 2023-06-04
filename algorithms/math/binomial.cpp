#include <algorithm>
#include <exception>
#include <iostream>
using namespace std;

long long int binomialCoefficient(int n, int k) {

    /**
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

int main() {

    cout<< binomialCoefficient(10,3) << "\n";
    cout<< binomialCoefficient(6,5) << "\n";

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