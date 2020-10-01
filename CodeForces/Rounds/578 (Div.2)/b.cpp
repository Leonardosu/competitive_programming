#include <bits/stdc++.h>
#define N 110 
using namespace std;

int v[N],t;
int n,m,k;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k; bool impossible = false;

		for(int i=1;i<=n;++i)
		cin>>v[i];

		for(int i=1;i<n;++i)
		{
			m+=v[i] - max(0,v[i+1]-k);				
			if(m<0)
			{
				cout<<"NO\n"; impossible = true;
				break;
			}
		}
		if(!impossible)
			cout<<"YES\n";
	}	
}