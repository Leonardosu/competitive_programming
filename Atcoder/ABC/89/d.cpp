#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<ll, pii> pos;
	ll n, m, d, k;
    cin>>n>>m>>d;

    dist[0] = 0;
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=m;++j)
    	{
    		cin>>grid[i][j];
    		pos[grid[i][j]] = {i,j};
    	}

    k = n * m;
    ll grid[n+1][m+1];
	ll dist[k+1];

    for(int i=d;i<=k;++i)
    {
		pii a = pos[i], b = pos[i-d];
		dist[i] = dist[i-d] + abs(a.f - b.f) + abs(a.s - b.s);
    }

    int q;
    cin>>q;
    for(int w=0;w<q;++w)
    {
    	ll ini, fim;
    	cin>>ini>>fim;
    	cout<<dist[fim] - dist[ini]<<"\n";
    }

}