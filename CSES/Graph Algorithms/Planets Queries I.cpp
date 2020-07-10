#include <bits/stdc++.h>
using namespace std;
const int N = 200010;

int n,q;
int next[32][N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>q;

	for(int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		next[0][i] = x;
	}
	
	for(int lv = 1;lv <= 31;++lv)	
		for(int i=1;i<=n;++i)
			next[lv][i] = next[lv-1][next[lv-1][i]];

	while(q--)
	{
		int x,k,ans;
		cin>>x>>k;
		while(k >= 0)
		{
			// cout<<"merda!!\n";
			for(int i = 30;i>=0;--i)
				if(1LL<<i <= k)
				{
					x = next[i][x];
					k -= 1LL<<i;
					break;
				}

			if(k == 0)
				break;			
		}

		cout<<x<<"\n";
	}

}