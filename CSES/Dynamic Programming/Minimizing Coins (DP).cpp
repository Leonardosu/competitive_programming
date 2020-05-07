#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 110;
const int M = 2e6 + 121;
const int INF = 1e9;

int coins[N],val[M];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for(int i=1;i<M;++i) val[i] = INF;

	int n,k,x;

	cin>>n>>k;
	
	for(int i=1;i<=n;++i)
	{
		cin>>coins[i];
		val[coins[i]] = 1;
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int x=1;x <= 1e6;++x)
		{
			int novo = x + coins[i];
			val[novo] = min(val[novo],val[x] + 1);
		}
	}

	if(val[k] == INF) cout<<"-1\n";
	else	cout<<val[k]<<"\n";
}
