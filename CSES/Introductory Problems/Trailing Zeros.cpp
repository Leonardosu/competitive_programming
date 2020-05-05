#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
typedef long long int ll;

ll ans = 0,n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(ll i=5;i<=n;i+=5)
	{
		ll x = i;
		while(x%5 == 0)
			ans++,x/=5;
	}
	cout<<ans<<"\n";
}
