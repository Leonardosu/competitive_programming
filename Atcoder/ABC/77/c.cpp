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
mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n;
    cin>>n;

    vi a(n), b(n), c(n);
    for(auto &x: a)
        cin>>x;
    for(auto &x: b)
        cin>>x;
    for(auto &x: c)
        cin>>x;

    sort(all(a));
    sort(all(b));
    sort(all(c));

    ll ans=0;
    for(int mid:b) {
        auto it1 = lower_bound(all(a), mid);
        auto it2 = upper_bound(all(c), mid);        
        ll qnt1=0,qnt2=0;

        if(it1 != a.begin()) {
            qnt1 = max(0, int(it1 - a.begin()));
        }

        if(it2 != c.end()) {
            qnt2 = n - int(it2 - c.begin());
        }
        ans += qnt1*qnt2;
    }

    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}