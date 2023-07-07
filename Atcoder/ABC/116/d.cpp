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
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int N = 1e5+7;
ll f[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n, k;

    cin>>n>>k;
    vector<pii> v(n);
    
    for(auto &[t, x] : v) {
    	cin>>t>>x;
    }

    sort(all(v), [&](pii a, pii b){
        return a.s > b.s;
    });

    priority_queue<ll, vector<ll>, greater<ll>> extras;
    ll ans=0, cnt=0;

    int i=0;
    for(i=0;i<k;++i) {
        auto [t, x] = v[i];
        (f[t]++ ? extras.push(x) : void(cnt++));
        ans += x;
    }

    ans += cnt*cnt;
    ll curr = ans;

    while(!extras.empty() && i<n) {
        int old = extras.top();
        extras.pop();

        auto [t, x]=v[i];
        curr += x - old;

        if(f[t]==0) {
            curr += 2LL*cnt + 1;
            cnt++;
            f[t]++;
        } else {
            extras.push(x);
        }

        ans = max(ans, curr);
        i++;
    }

    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}