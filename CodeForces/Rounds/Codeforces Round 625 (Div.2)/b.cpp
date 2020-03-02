#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
const int N = 4e5 + 7;
const int INF = 1e9;
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int t;

vector<ii> v;
int n,ans,best;

vector<ll> g[2*N + 7];
void solve()
{
	for(int i=0;i<n;++i)
	{
		int dif = i - v[i].f;
		dif+=N;
		g[dif].pb(i);
	}

	ll best = 0;
	ll sum;

	for(int i=0;i<2*N;++i)
		if(g[i].size() > 0)
		{
			sum = 0;
			for(int j=0;j<g[i].size();++j)
				sum+=v[g[i][j]].f;	

			best = max(sum,best);		
		}
	cout<<best<<"\n";	
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>n;
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i].f;
		v[i].s = i;
		best = max(best,v[i].f);
	}
	

	solve();
	cout<<"\n";
}