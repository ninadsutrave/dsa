/* Here's my template for competitive coding */

#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <cstring> 
#include <algorithm>
#include <cmath>
#include <math.h>
#include <queue>
#include <stack>
#include <iomanip>
#include <iostream> 
using namespace std;

#define get(a, type, N)     vector<type> a(N); for(long long int i = 0; i<N; ++i) cin>>a[i];
#define show(a,N)           for(long long int i = 0; i<N; ++i) cout<<a[i]<<" "; cout<<"\n";
#define f(i,N)              for(long long int i = 0; i<N; ++i)
#define yes                 cout<<"YES"<<"\n";
#define no                  cout<<"NO"<<"\n";
#define ll                  long long int
#define ull                 unsigned long long int
#define setBits(x)          __builtin_popcountll(x)
#define zeroBits(x)         __builtin_ctzll(x)
#define mod                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define all(x)              x.begin(),x.end()
#define mset(x,a)           memset(x, a, sizeof(x));
#define ios                 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

//sieve
vector<bool> isPrime;
vector<ll> spf;
void sieve(ll N) {
    isPrime.resize(N+1, true);
    spf.resize(N+1, -1);
    isPrime[0] = isPrime[1] = false;

    for(ll i = 2; i*i<N; ++i) {
        if(isPrime[i]) {
            spf[i] = i;

            for(ll j = i*i; j<N; j = j+i) {
                isPrime[j] = false;
                spf[j] = i;
            }
        }
    }
}

// add hash for pair<int,int> in map
// add segment tree
// add modular operations
// add graph

void solve() {

    ll N;
    cin>>N;

}

int main() {
	//sieve();
	ios

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
    ll test;
    cin>>test;
    
    while(test--) solve();

	return 0;
}