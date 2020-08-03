#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;

ll gcd(ll a,ll b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

int n,t;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.resize(n);
		for(int i=0;i<n;++i)
			cin>>v[i];
		
		sort(all(v));

		int par = 0,impar = 0;
		for(int i=0;i<n;++i)
		{
			if(v[i]&1) impar++;
			else par++;
		}
		bool ok = false;
		if(par%2 == 0 && impar%2 == 0)
		{
			cout<<"YES\n";
			continue;
		}

		if(par&1 && impar&1)
		{
			for(int i=1;i<n;++i)
			{
				if( v[i] - v[i-1] == 1)
				{
					ok = true;
					break;
				}

			}
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";		
	}
}