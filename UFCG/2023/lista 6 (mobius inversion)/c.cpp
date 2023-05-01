#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 100000 + 7;
const int mod = 1e9 + 7;

inline ll poww(ll a, ll b){ll res = 1LL;while (b > 0LL){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}
int mobius[N];
int limit;

void init() {
	for(int i=1;i<N;++i) {
		mobius[i] = (i == 1) - mobius[i];
		for(int j=i;(j+=i)<N;)
			mobius[j] += mobius[i];
	}
}

int freq[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    init();

    int n;
    cin>>n;
    for(int i=0;i<n;++i) {
    	int x;
    	cin>>x;

    	limit = max(limit, x);
    	for(int j=2;j*j<=x;++j) {
    		if(x%j == 0) {
    			if(x/j != j) freq[x/j]++;
    			freq[j]++;
    		}
    	} 
    	
    	if(x > 1)
    		freq[x]++;
    }

    ll total = poww(2, n) - 1;
    for(int g=1;g<=limit;++g) {
    	ll now = poww(2, freq[g]) - 1;
    	total = (total + now * mobius[g])%mod;
    	if(total < 0)
    		total += mod;
    }

    cout<<total<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}