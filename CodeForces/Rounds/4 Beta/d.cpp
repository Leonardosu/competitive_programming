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

    int n, a, b;
    cin>>n>>a>>b;
    vector<array<int, 3>> v;   

    for(int i=1;i<=n;++i) {
    	int x, y;
    	cin>>x>>y;
    	if(x > a && y > b) {
    		v.pb({x, y, i});
    	}
    }

    sort(ALL(v));    
    n = sz(v);
    if(n == 0) {
    	cout<<"0\n";
    	return 0;
    }

    int dp[n]; //dp[i] max chain size that last chain is i
    int prev[n]; 
    memset(dp, 0, sizeof dp);
    memset(prev, -1, sizeof prev);

    int ans = 0, id = 0;
    for(int i=0;i<n;++i) {
    	int &now = dp[i];
    	for(int j=0;j<i;++j) {
    		if(v[j][0] < v[i][0] && v[j][1] < v[i][1] && now < dp[j]) {
    			prev[i] = j;
    			now = dp[j];
    		}
    	}
    	now += 1;
    	if(now > ans)
    		ans = now, id = i;
    }

    vector<int> ids;
    while(id != -1) {
    	ids.pb(v[id][2]);
    	id = prev[id];
    }

    cout<<ans<<"\n";
    reverse(ALL(ids));
    for(int &x : ids)
    	cout<<x<<" ";
}