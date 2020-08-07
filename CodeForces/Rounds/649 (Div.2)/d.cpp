#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 1e5 + 7;
const int inf = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

vector<int> g[maxn];
int dist[maxn],pai[maxn],color[maxn];
int cnt1,cnt2,ans = 1e9,cara;
int n,m,k;

// bool bipartido = true;

void get1(int x,int cor) // se é bipartido
{
	color[x] = cor;

	for(int &y : g[x])
	{
		if(color[y] == cor)
			color[x] = -2;
			
 		if(color[y] == -1)
		{
			get1(y,!cor);
		}
	}

	if(color[x] == 0) cnt1 ++;
	else if(color[x] == 1) cnt2 ++;
}

void get2(int cor) // print
{
	int cnt = (k+1)/2;

	cout<<"1\n";
	for(int i=1;i<=n && cnt;++i)
		if(color[i] == cor)
		{
			cout<<i<<" ";
			cnt--;			
		}
	cout<<"\n";
}

void dfs(int x)
{
	for(int &y : g[x])
	{
		if(y == pai[x]) continue;

		if(dist[y] == -1)
		{
			dist[y] = dist[x] + 1;
			pai[y] = x;
			dfs(y);
		}

		else if(dist[y] < dist[x])
		{
			int ciclo = dist[x] - dist[y] + 1;
			if(ciclo < ans)
				ans = ciclo,cara = x;			
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) dist[i] = -1,color[i] = -1;

	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}

	//******************
	// Ans type 1 :
	cnt1 = cnt2 = 0;
	get1(1,0);
	
	if(cnt1 >= (k+1)/2)
	{
		get2(0);
		return 0;
	}
	if(cnt2 >= (k+1)/2)
	{
		get2(1);
		return 0;
	}
	//******************

	// Ans type 2 :
	dist[1] = 0;
	dfs(1);
	
	cout<<"2\n"<<ans<<"\n";
	for(int i=0;i<ans;++i)
	{
		cout<<cara<<" ";
		cara = pai[cara];
	}

	cout<<"\n";
}