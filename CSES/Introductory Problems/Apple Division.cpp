#include <bits/stdc++.h>
using namespace std;
const int N = 26;
typedef long long int ll;


ll v[N],best[N];
int n;

ll solve(int i,ll a,ll b)
{
	if(i == n + 1)
		return best[n] = min(abs(a-b),best[n]);	
	return best[i] = min(solve(i+1,a+v[i],b),solve(i+1,a,b+v[i]));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i) cin>>v[i];
	for(int i=1;i<=n;++i) best[i] = 1e9;
	solve(1,0LL,0LL);

	cout<<best[n]<<'\n';
}