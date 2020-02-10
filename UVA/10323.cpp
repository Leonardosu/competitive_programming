#include <bits/stdc++.h> 
using namespace std;

typedef long long int ll;

ll ans,n;
ll f[21];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ans = 1LL;
	for(ll i=1;i<=10005;++i)
	{
		ans*=i;
		if(ans > 6227020800)
			break;		
		f[i] = ans;
	}

	while(cin>>n)
	{
		if(n < 0)
		{
			if(n%2 == 0) n = 0;
			else n = 15;
		}

		if(n < 8) cout<<"Underflow!\n";
		else if(n >= 14) cout<<"Overflow!\n";
		else cout<<f[n]<<"\n";			
		
	}	
}