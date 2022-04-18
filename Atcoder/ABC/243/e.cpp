#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 302;
const ll INF = 1e16;

ll cost[N][N];
int n, m;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for(int i=0;i<=n;++i)
    	for(int j=0;j<=n;++j)
    		cost[i][j] = INF;

    vector<array<int,3>> edges;
    for(int i=0;i<m;++i)
    {
    	int x,y,c;
    	cin>>x>>y>>c;
    	x--, y--;

    	edges.pb({x,y,c});
    	cost[x][y] = cost[y][x] = c;
    }

    
    for(int k=0;k<n;++k)
    	for(int i=0;i<n;++i)
    		for(int j=0;j<n;++j)
    			cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);

    int qnt = 0;
    for(auto &edge: edges)
    {
    	int x = edge[0], y = edge[1], c = edge[2];
    	bool lixo = false;
    	for(int k=0;k<n;++k)
    		if(cost[x][k] + cost[k][y] <= c)
    		{
    			lixo = true;
    			break;
    		}
    	qnt += lixo;
    }

    	
    cout<<qnt<<"\n";
}