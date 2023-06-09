#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void sieve(vector<int>& primes, int N) {
    
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i<N; ++i) {
        if(isPrime[i]) {
            for(int j = i*i; j<N; j = j+i) {
                isPrime[j] = false;
            }
        }
    }

    for(int i = 0; i<N+1; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
}

void segmentedSieve(long long int left, long long int right, vector<int> lookup, vector<long long int>& allPrimes) {
    
  vector<bool> isPrime(right - left + 1, true);

  // Looping over all the primes
  for (long long  int p : lookup) {

      // Choosing the first multiple of p >= left
      long long int s = left / p * p;
      if (s < left) {
          s = s + p;
      }

      // Cancelling out the factors of p
      for (long long int i = s; i <= right; i = i + p) {
          isPrime[i - left] = false;
      }
  }

  // Append primes in range [left, right] in ans
  for (int i = 0; i < isPrime.size(); i++) {
      if (isPrime[i]) {
          allPrimes.push_back(i + left);
      }
  }
}

int main() {

    long long int N = 1e12;
    vector<int> lookup;
    int segmentLength = sqrt(N);
    sieve(lookup, segmentLength);

    vector<long long int> allPrimes;
    for (long long int L = 2; L<N; L = L + segmentLength) {
        long long int R = min(L + segmentLength - 1, N - 1);
        segmentedSieve(L, R, lookup, allPrimes);
    }

    for(long long int p: allPrimes) {
        cout<<p<<" ";
    }

    return 0;
}

/**
 * 
 * Segmented Sieve
 * 
 * Since storing arrays of length greater than 1e6 gives memory limit error,
 * for N > 1e6, the simple sieve algorithm would not be optimal
 * 
 * So for larger N, segmented sieve algorithm works by breaking the range [2,N] into 
 * segments of length √N
 * 
 * First generate all primes from 2 to floor(√N) and store separately for lookup
 * 
 * Use this lookup to cancel multiples of these primes in the different segments [L,R]
 * After marking the multiples as false, the remaining ones true are the primes
 * 
 * This is the most optimal way to go for questions where we have to print all primes
 * between [L,R] when (R-L) <= 1e6
 * 
 * If we are given multiple ranges [L1, R1], [L2, R2], [L3, R3] ... [Lk, Rk]
 * First perform simple sieve till N = √max(R1, R2 ... Rk)
 * 
 * Time complexity : O(N * log(logN))
 * Space complexity: Θ(√N)
 * 
*/
