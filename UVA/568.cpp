#include <bits/stdc++.h> 
using namespace std;

typedef long long int ll;
ll n,ans,c,c2,c5,now;
ll f[10010];

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
	
	ans = 1LL;
	f[0] = 1;
	c2 = 0;
	c5 = 0;
	for(ll i=1;i<=10005;++i)
	{
		c = i;

		while(c%2 == 0) c/=2,c2++;
		while(c%5 == 0) c/=5,c5++;
		ans*=c;
		ans%=10;	
		now = (ans*poww(2,c2-c5))%10;		
		f[i] = now;
	}

	while(cin>>n)
	{
		cout<<setw(5);
		cout<<n<<" -> "<<f[n]<<"\n";	
	}	
}