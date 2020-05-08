#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long int ll;

bool seen[N];
vector<int> g[N],ans;
int n,m;

void dfs(int x)
{
	seen[x] = true;
	for(int i=0;i<g[x].size();++i)
		if(!seen[g[x][i]])
			dfs(g[x][i]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) seen[i] = false;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);

	for(int i=2;i<=n;++i)
		if(!seen[i])
		{
			dfs(i);
			ans.push_back(i);
		}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();++i)
		cout<<"1 "<<ans[i]<<'\n';

}