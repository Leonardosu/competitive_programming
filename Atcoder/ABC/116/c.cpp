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


vi v;
int solve(int l, int r) {
	if(l > r) return 0;
	if(l == r) return v[l];

	int menor = 1e5, id = 0;
	for(int i=l;i<=r;++i) {
		if(v[i] < menor)
			menor = v[i], id = i;
	}

	for(int i=l;i<=r;++i)
		v[i] -= menor;

	return menor + solve(l, id-1) + solve(id+1, r);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    

    int n;
    cin>>n;

    // int maior = -1;
    // vi v;
    for(int i=0;i<n;++i) {
    	int x; cin>>x;
    	v.pb(x);
    }

    // int ans = 0;
    // for(int i=0;i<n;++i) {
    // 	if(v[i] == 0) continue;
    // 	ans += v[i];
    // 	for(int j=i;j<n;++j) {
    // 		if(v[j] < v[i]) break;
    // 		v[j] -= min(v[j], v[i]);
    // 	}
    // }

    // v.pb(-1);

    // int ans = 0;
    // for(int i=1;i<=n+1;++i) {
    // 	if(v[i-1] > v[i]) {
    // 		ans += maior;
    // 		cout<<i<<" ->"<<maior<<endl; 		
    // 		maior = v[i];   
    // 	} else {
    // 		maior = max(maior, v[i]);
    // 	}
    // }

    cout<<solve(0,n-1)<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}