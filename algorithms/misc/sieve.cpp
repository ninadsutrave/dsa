#include <vector>
using namespace std;

void sieve(vector<bool>& isPrime, vector<int>& spf, int N) {

    isPrime.resize(N+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i<N; ++i) {

        if(isPrime[i]) {
            spf[i] = i;

            for(int j = i+i; i<N; j = j+i) {
                isPrime[j] = false;
                spf[j] = i;
            }
            
        }

    }

}

/**
 * Time complexity analysis:
 * Multiples of k will be cancelled out in n/k iterations
 * 
 * Thus time taken = O(n* sum(n/k))
 * 
 * sum(n/k) = 1/2 + 1/3 + 1/5 + 1/7 + 1/11 + ...
 *          = ln(ln(kmax)) 
 *          (where kmax is the largest prime number k)
 * 
 * Thus Time Complexity is O(nlog(logkmax))
 * 
 * Applications of spf:
 *  Finding prime factorisation of numbers in O(logn) time per query
*/
