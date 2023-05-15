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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
 

 	map<ll,ll> freq;
 	int n;
 	cin>>n;
 	for(int i=0;i<n;++i){
 		ll x;
 		cin>>x;
 		freq[x]++;
 	}

 	vector<ll> sticks;
 	for(auto [x, qnt] : freq) {
 		if(qnt >= 4) {
 			sticks.pb(x);
 		}

 		if(qnt >= 2) {
 			sticks.pb(x);
 		}

 	}

 	sort(all(sticks));
 	reverse(all(sticks));
 	ll ans = 0;
 	if(sz(sticks) >= 2) 
 		ans = sticks[0] * sticks[1];
 	cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}