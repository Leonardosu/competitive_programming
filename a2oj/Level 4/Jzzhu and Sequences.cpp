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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll x, y, n;
    const ll mod = 1e9 + 7;

    //fn = fn-1 - fn-2
    cin>>x>>y>>n;
    vector<ll> f = {x,y,y-x,-x,-y,x-y};
    ll ans;

    if(n%6 == 0)
    	n = 6;
    else
    	n %= 6;

    ans = f[n - 1]%mod;

    if(ans < 0)
    	ans += mod;
    cout<<ans<<"\n";
}