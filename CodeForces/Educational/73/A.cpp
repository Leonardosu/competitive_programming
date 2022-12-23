#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
 
const int N = 200;
 
typedef long long int ll;
 
int v[N];
int t,n,x;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>t;
 
	while(t--)
	{
		cin>>n;
		memset(v,0,sizeof(v));
	
		for(int i=1;i<=n;++i)
		{
			cin>>x; 
			int pot = 0;
			while(x>0)
			{
				x/=2;
				pot++;
			}
			v[pot]++;
		}
 
		for(int i=1;i<=12;++i)
		{
			int up = v[i];
			up/=2;
			v[i+1] +=up;
		}
 
		if(v[12] >= 1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}