#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

inline ll poww(ll a, ll b, ll mod){ll res = 1;while (b > 0){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}
const int mod = 1e9 + 7;

ll ans = 1LL;
ll n,m,inverso;
vector<ii> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	inverso = poww(2LL,mod-2,mod);
    cin>>n>>m;

    for(int i=0;i<m;++i)
    {
        ll x,y;
        cin>>x>>y;
        v.pb({x,y});
    }    


    for(ll i=1;i<=n;++i)
    	ans = (ans*i)%mod;
    for(ll i=1;i<=m;++i)
    	ans = (ans*inverso)%mod;    

    cout<<ans<<"\n";
}