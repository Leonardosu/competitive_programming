#include <bits/stdc++.h> // ~~O(M)
using namespace std;

typedef long long int ll;
ll n,m,ans,c,c2,c5;

ll poww(ll a,ll n)
{
	ll ans = 1;
	while(n > 0)
	{
		if(n&1) ans = (ans*a)%10;
		a = (a*a)%10;
		n >>= 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while(cin>>n>>m)
	{
		ans = 1LL;
		c2 = 0;
		c5 = 0;
		for(ll i=n-m+1;i<=n;++i)
		{
			c = i;
			while(c%2 == 0) c/=2,c2++;
			while(c%5 == 0) c/=5,c5++;
			ans*=c;
			ans%=10;
		}
		if(c2 > c5)
			ans = (ans*poww(2,c2-c5))%10;
		else
			ans = (ans*poww(5,c5-c2))%10;
		cout<<ans<<"\n";
	}
}