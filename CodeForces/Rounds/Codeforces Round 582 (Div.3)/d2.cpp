#include <bits/stdc++.h>
#define N 200010
using namespace std;
 
typedef long long int ll;
 
vector<int> save[N];
int n,k,x;
ll  ans = 9999999999999;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>n>>k;
 
	for(int i=0;i<n;++i)
	{
		cin>>x;
		int cont = 0;
 
		while(x > 0)
		{
			save[x].push_back(cont);
			cont++;
			x/=2;
		}
 
		save[0].push_back(cont);
	}
 
	for(int i=1;i<N;++i)
	{
		if(save[i].size() < k) continue;
 
		sort(save[i].begin(),save[i].end());
 
		ll sum = 0;
 
		for(int j=0;j<k;++j)
			sum+=save[i][j];
 
		ans = min(ans,sum);
	}
 
	cout<<ans<<"\n";
}