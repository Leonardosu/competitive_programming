#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 1e5 + 7;
int v[maxn];
int t,ini,fim;
ll now,best;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		int n,x;
		now = 0,best = -1;
		
		cin>>n>>x;
		for(int i=1;i<=n;++i)
			cin>>v[i];

		for(int i=1;i<=n;++i)
		{
			now += v[i];
			if(now%x) best = max(best,i + 0LL);
		}

		now = 0LL;
		for(int i=n;i>=1;--i)
		{
			now += v[i];
			if(now%x) best = max(best,n - i + 1LL);
		}

		cout<<best<<"\n";
	}
}