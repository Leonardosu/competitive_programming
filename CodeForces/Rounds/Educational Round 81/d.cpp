#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1;
const int INF = 1e9;
typedef long long int ll;

int t;
ll a,m,g;

ll phi(ll n)
{
	ll ans = n;
	for(ll i = 2;i*i<=n;++i)
	{
		if(n%i == 0)
		{
			while(n%i == 0)
				n/=i;
			ans -= ans/i;
		}
	}
	
	if(n > 1)
		ans-=ans/n;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>a>>m;
		cout<<phi(m/__gcd(a,m))<<"\n";
	}

}