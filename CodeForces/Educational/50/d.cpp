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
typedef vector<ll> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    ll sum = 0;
    int n, m;
    cin>>n;
    vi a(n);
    for(ll &x : a) {
    	cin>>x;
    	sum += x;
    }

    cin>>m;
    vi b(m);
    for(ll &x : b) {
    	cin>>x;
    	sum -= x;
    }

    if(sum != 0) {
    	cout<<"-1\n";
    	return 0;
    }

    ll ans = 0;
    int i = 0, j = 0;
    ll s1 = a[0], s2 = b[0];
    bool ok = true;

    while(i<n && j<m) {
    	if(s1 == s2) {
    		i++, j++;
    		if(i<n)    		
    			s1 = a[i];
    		if(j<m)
    			s2 = b[j];
    		ans++;
    	} else if(s1 > s2) {
    		j++;
    		if(j > m) {
    			ok = false;
    			break;
    		}
    		s2 += b[j];
    	} else {
    		i++;
    		if(i > n) {
    			ok = false;
    			break;
    		}
    		s1 += a[i];
    	}
    }

    if(!ok) cout<<"-1\n";
    else cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}