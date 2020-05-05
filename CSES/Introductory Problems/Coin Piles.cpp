#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int t;
ll x,y,a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		bool ok = false;
		a = 2LL*x - y;
		b = 2LL*y - x;
		if(a >= 0 && b >=0 && a%3 == 0 && b%3 ==0)
			ok = true;
		
		if(ok)cout<<"YES\n";
		else cout<<"NO\n";
	}	

}
