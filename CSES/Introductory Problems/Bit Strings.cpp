#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
typedef long long int ll;

ll ans = 0,n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	ans = 1;
	for(int i=1;i<=n;++i)
		ans = (ans*2LL)%MOD;
	cout<<ans<<"\n";
}
