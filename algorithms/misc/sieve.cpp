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