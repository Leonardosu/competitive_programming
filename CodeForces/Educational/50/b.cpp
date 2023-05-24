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


void solve_task() {
	ll x, y, k;
	cin>>x>>y>>k;
	ll moves = max(x, y);
	
	if(moves > k) {
		cout<<"-1\n";
	} else {
		ll ans = k;
		if((x+y)%2 == 1) { //x e y diferente
			ans--; 
			//removo uma diagonal, pra corrigir
		} else if((x+k)%2 == 1) {
			//tem um passo a mais, tiro 2
			ans-=2;
		}
		cout<<ans<<endl;
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();

    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}