#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1;
const int INF = 1e9;
typedef long long int ll;
typedef pair<ll,int> ii;
typedef pair<int,ii> iii;

vector<ll> a;
vector<ii> b;
vector<ll> divisores;
set<ll> test;
ll n,m,y,x;

ll _gcd(ll a, ll b)
{
    if (a == 0LL)
        return b;
    return _gcd(b % a, a);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		a.pb(x);
	}
	for(int i=0;i<m;++i)
	{
		cin>>x;
		b.pb(mp(x,i+1));
	}

	sort(all(a));

	ll gcd = a[1] - a[0];
	
	for(int i=0;i<n-1;++i)
	{
		ll aux = a[i+1] - a[i];
		gcd = _gcd(gcd,aux);
	}
	
	ll ans = -1;
		
	for(int i=0;i<b.size();++i)
		if(gcd%b[i].f == 0)
		{
			ans = b[i].s;
			break;
		}
	
	if(ans == -1) cout<<"NO\n";
	else	cout<<"YES\n"<<a[0]<<" "<<ans<<"\n";
	// cout<<gcd<<"\n";
}