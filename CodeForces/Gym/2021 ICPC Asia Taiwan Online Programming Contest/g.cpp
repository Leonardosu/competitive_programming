#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define int long long

int vis[MAX];
vector<pair<int, int> > g[MAX];
vector<int> res[MAX];

void dfs(int node){
	vis[node]=true;
	int re=0;
	for (int i=0; i<(int)g[node].size(); i++){
		int v=g[node][i].second;
		if (!vis[v]) dfs(v);
		int l=0;
		int r=(int)g[v].size()-1;
		int pos=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if (g[v][mid].first>g[node][i].first){
				pos=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		if (pos!=-1) re+=res[v][pos];
		re++;
		res[node].push_back(re);
		
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for (int i=0; i<n-1; i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		int w;
		cin>>w;
		g[x].push_back({w,y});
		g[y].push_back({w,x});
	}
	for (int i=0; i<n; i++){
		sort(g[i].begin(), g[i].end());
		reverse(g[i].begin(), g[i].end());
	}
	dfs(0);
	int ans=0;
	for (int i=0; i<n; i++){
		ans+=res[i][(int)g[i].size()-1];
	}
	cout<<ans<<endl;
	
}
