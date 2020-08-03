#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 1e5 + 7;
const int inf = 1e9;

int v[maxn],aux[maxn];
ll ans,now,temp;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	
	cin>>n;	
	for(int i=1;i<=n;++i) cin>>v[i];

	for(int xx = -30;xx<=30;++xx)
	{
		for(int i=1;i<=n;++i)
		{
			if(v[i] > xx) aux[i] = -inf;
			else aux[i] = v[i];
		}

		now = temp = 0;
		now = xx;

		for(int i=1;i<=n;++i)
		{
			temp += aux[i];
			if(now < temp) now = temp;
			if(temp < 0) temp = 0;			
		}
		
		ans = max(ans,now - xx);
	}

	cout<<ans<<"\n";
}