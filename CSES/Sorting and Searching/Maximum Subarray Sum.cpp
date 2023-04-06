#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    ll v[n];
    for(int i=0;i<n;++i)
    	cin>>v[i];

    ll ans = *max_element(v,v+n);
    ll cur = 0;
    for(int i=0;i<n;++i) {
    	cur += v[i];
    	if(cur < 0) cur = 0;
    	else ans = max(ans, cur);
    }
    
    cout<<ans<<"\n";
}