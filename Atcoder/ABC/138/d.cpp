#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 200010

using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

vector<ll> graph[N];
int val[N],ans[N];
bool vist[N];
int n,q,a,b,x;

void dfs(int t,ll carry)
{
	vist[t] = true;
	for(int i=0;i<graph[t].size();++i)
	{
		int j = graph[t][i];
		if(!vist[j])
			dfs(j,carry+val[j]),val[j]=carry+val[j];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n>>q;
	for(int i=1;i<=n;++i) vist[i] = false,val[i] = 0;

	for(int i=1;i<n;++i)
	{
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	int j;

	for(int i=1;i<=q;++i)
	{
		cin>>j>>x;
		val[j]+=x;
	}
	
	dfs(1,val[1]);
	for(int i=1;i<=n;++i)
		cout<<val[i]<<" ";
	cout<<"\n";
}