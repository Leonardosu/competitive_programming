#include <bits/stdc++.h>

using namespace std;

int t;
int a,b,c,d;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		double x = b*log(a);
		double y = d*log(c);
		// cout<<x<<" vs "<<y<<"\n";
		if(x < y) cout<<"<\n";
		else cout<<">\n";
	}
}