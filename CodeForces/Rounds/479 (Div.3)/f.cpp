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
    
    map<int,int> dp, pos;
    int n;
    cin>>n;

    vi v;
    int last = 0, best = 0;
    for(int i=1;i<=n;++i) {
    	int x;
    	cin>>x;
    	v.pb(x);
    	int longest = dp[x-1] + 1;
    	dp[x] = max(dp[x], longest);

    	if(best < dp[x]) {
    		best = dp[x];
    		last = x;
    	}
    }

    vi res;
    for(int i=n-1;i>=0;--i) {
    	if(v[i] == last) {
    		res.pb(i+1);
    		last--;
    	}
    }

    reverse(all(res));
    cout<<best<<endl;
    for(int x : res) {
    	cout<<x<<" ";
    }
    cout<<endl;

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}