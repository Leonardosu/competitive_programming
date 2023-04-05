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
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin>>n>>k;

    vi v;
    for(int i=0;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	if(y <= k) {
    		v.pb(x);
    	}
    }
    sort(all(v));
    if(v.empty()) cout<<"TLE\n";
    else cout<<v[0]<<"\n";
}