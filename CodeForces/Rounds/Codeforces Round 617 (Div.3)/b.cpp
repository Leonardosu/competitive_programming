#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;

typedef pair<int,int> ii;
typedef long long int ll;

vector<ll> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll p = 1;

	for(int i=1;i<=11;++i)
	{
		v.pb(p);
		p*=10;
	}

	int t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		ll ans = x;

		while(x > 0)
		{
			for(int i=0;i<v.size();++i)
				if(v[i+1] > x)
				{
					ans += v[i]/10LL;
					x +=v[i]/10LL;
					x -= v[i];
					break;
				}
		}

		cout<<ans<<"\n";
	}
	
}