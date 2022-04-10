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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,x;
	cin>>n>>m>>x;
	int custo[n+1];
	memset(custo,0,sizeof(custo));
	for(int i=0;i<m;++i)
	{
		int x;
		cin>>x;
		custo[x] = 1;
	}

	int ans = n + 1,curr = 0;
	for(int i=x;i>=0;--i)
		curr += custo[i];
	ans = curr;
	curr = 0;
	for(int i=x;i<=n;++i)
		curr += custo[i];
	cout<<min(ans,curr)<<"\n";
	// memset(next,-1,sizeof(next));

}