#include <bits/stdc++.h> //	~~ O(log(p))
using namespace std;	// Binary Exponentiation Modular

typedef long long int ll;

ll b,p,m,prod;

ll poww(ll a,ll n)
{
	ll ans = 1;
	while(n > 0)
	{
		if(n&1) ans = (ans*a)%m;
		a = (a*a)%m;
		n >>= 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while(cin>>b)
	{
		cin>>p>>m;
		cout<<poww(b,p)<<"\n";
	}
}