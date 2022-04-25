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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m, q;
    cin>>n>>m>>q;

    int grid[n+2][m+2];
    bool vis[n+2][m+2];

    memset(grid, -1,sizeof(grid));
    memset(vis, false, sizeof(vis));

    map<int,int> ans;
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=m;++j)
    	{
    		char c;
    		cin>>c;
    		if(c == '.')
    			grid[i][j] = 0;
    	}

    int color = 1;
    while(q--)
    {
    	int x,y;
    	cin>>x>>y;
    	// x--, y--;

    	if(grid[x][y] != 0)
    		cout<<ans[grid[x][y]]<<"\n";
    	else
    	{
			int qnt = 0;					
			
			queue<pii> Q;
			Q.push({x,y});
			
			int dx[] = {1,-1,0,0};
			int dy[] = {0,0,-1,1};

			while(!Q.empty())
			{
				auto [x,y] = Q.front(); Q.pop();

				vis[x][y] = true;
				grid[x][y] = color;

				for(int k=0;k<4;++k)
				{
					int xx = dx[k] + x, yy = dy[k] + y;
					if(!vis[xx][yy])
					{
						if(grid[xx][yy] == -1)
							qnt++;
						else if(grid[xx][yy] == 0)
						{
							vis[xx][yy] = true;
							Q.push({xx, yy});
						}
					}
				}
			}

			ans[color] = qnt;
			color++;
			cout<<qnt<<"\n";
		}
    }
}