#include <vector>
#include <iostream>
using namespace std;

void sieve(vector<bool>& isPrime, vector<int>& spf, int N) {
    
    isPrime.resize(N+1, true);
    spf.resize(N+1, -1);
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

int main() {

    int N = 1e6;
    vector<bool> isPrime;
    vector<int> spf;

    sieve(isPrime, spf, N);
    cout<<isPrime[42517]<<"\n";
    cout<<isPrime[34193]<<"\n";
    cout<<isPrime[455231]<<"\n";
    
    int num = 99684;
    while(num) {
        cout<<spf[num]<<" ";
        num  = num/spf[num];
    }

    return 0;
}

/**
 * 
 * Number of primes between 1 to n is roughly n/ln(n)
 *  
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
