#include <bits/stdc++.h>
using namespace std;

int x,y,z,a,b,c,n;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x>>y>>z;
		a+=x;
		b+=y;
		c+=z;
	}

	if(a==0 && b==0 && c==0) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}