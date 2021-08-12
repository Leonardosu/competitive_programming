#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ways = 0,n;
vector<int> g[21];

// impostor nao aponta pra impostor

void solve(int i,int mask)
{
	if(i == n)
	{
		bool valid = true;
		bool impostor[n];
		memset(impostor,false,sizeof(impostor));

		for(int i=0;i<n;++i)
			if(mask&(1<<i))
				impostor[i] = true;

		for(int i=0;i<n;++i)
		{
			if(impostor[i]) //impostor aponta pra outro
			{
				for(int &x:g[i])
					if(impostor[x])
					{						
						valid = false;
						break;
					}
			}
			else
			{
				int cnt = 0;
				for(int &x:g[i])
					if(impostor[x])
						cnt++;
				if(!cnt)
				{					
					valid = false;
					break;
				}
			}
		}

		if(valid)
			ways++;
		
		return;
	}

	
	solve(i+1,mask);
	solve(i+1,mask|(1<<i));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int q,x;
		cin>>q;
		for(int j=0;j<q;++j)
		{
			cin>>x;
			g[i].pb(x-1);
		}
	}
	
	// 11111
	solve(0,0);

	cout<<ways<<"\n";
}