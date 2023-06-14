/* Here's my template for competitive coding */
/* Ninad Sutrave */
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

vector<ll> primes;
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

    for(ll i = 2; i<=N; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
    }
}

// unordered_map<pair<int, int>, bool, hash_pair> map;
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        return hash1;
    }
};

// add segment tree

ll modPower(ll base, ll exp, ll mod_) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base)%mod_;
        }
        exp = exp >> 1;
        base = (base * base);
    }
    return result % mod_;
}

void createGraph(vector<ll> adj[], ll V, ll E) {
    for(ll i = 0; i<E; ++i) {
        ll u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(vector<ll> adj[], vector<bool>& visited, ll src) {
    visited[src] = true;

    for(ll neighbour: adj[src]) {
        if(!visited[neighbour]) {
            dfs(adj, visited, neighbour);
        }
    }
}

void bfs(vector<ll> adj[], ll src, vector<bool>& visited) {
    queue<ll> q;
    q.push(src);

    while(q.size()) {

        ll node = q.front();
        q.pop();
        visited[node] = true;

        for(ll neighbour: adj[node]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
            }
        }
    }
}

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