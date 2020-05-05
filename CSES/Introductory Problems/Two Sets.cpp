#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;

ll n,sum;
vector<int> a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	sum = (n*(n+1))/2;
	if(sum%2) 
	{
		cout<<"NO\n";
		return 0;
	}

	if(n%2)
	{
		a = {1,2};
		b = {3};
		for(int i=7;i<=n;i+=4)
		{
			a.pb(i-3); a.pb(i);
			b.pb(i-2); b.pb(i-1);
		}
	}
	else
	{
		a = {1,4};
		b = {2,3};
		for(int i=8;i<=n;i+=4)
		{
			a.pb(i-3); a.pb(i);
			b.pb(i-2); b.pb(i-1);
		}
	}
	cout<<"YES\n";
	cout<<a.size()<<"\n";
	for(int i=0;i<a.size();++i) cout<<a[i]<<" ";
	cout<<"\n"<<b.size()<<"\n";
	for(int i=0;i<b.size();++i) cout<<b[i]<<" ";
}
