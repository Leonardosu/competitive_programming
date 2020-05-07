#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 110;
const int M = 2e6 + 121;
const int MOD = 1e9 + 7;

typedef long long int ll;

int coin[N],n;
ll way[M],k;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	memset(way,0,sizeof(way));
	
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>coin[i];
		way[coin[i]] = 1;
	}

	
	
	for(int x = 0;x < k;++x)
	{
		for(int i=1;i<=n;++i)
		{
			int xx = x + coin[i];
			if(xx > k) continue;
			way[xx] = (way[x] + way[xx])%MOD;

		}
		
	}

	cout<<way[k]<<"\n";
}