#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int maxn = 2e5 + 7;
vector<int> g[maxn];

bool possible;
int n,m;
int p[maxn],sum[maxn],h[maxn];
int quantos[maxn]; //quantos caras abaixo de mim tem


int good[maxn],bad[maxn];
int lv[maxn],resto[maxn];


ii solve(int x, int pai) 
{
	ii ret = {-p[x], p[x]};

	for (auto& y : g[x]) 
	{
		if (y == pai)
			continue;
		ii cur = solve(y, x);

		ret.f += cur.f;
		ret.s += cur.s;
	}

	if (h[x] < ret.f || h[x] > ret.s || (ret.s - h[x]) % 2)
		possible = false;
	ret.f = h[x];
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{

		cin>>n>>m;
		for(int i=0;i<n;++i)
		{
			g[i].clear();
			cin>>p[i];
		}
		for(int i=0;i<n;++i)
			cin>>h[i];

		for(int i=1;i<n;++i)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			g[a].pb(b);
			g[b].pb(a);
			lv[a]++;
			lv[b]++;
		}		


		possible = true;
		solve(0,-1);

		if(possible) cout<<"YES\n";
		else cout<<"NO\n";
	}

}