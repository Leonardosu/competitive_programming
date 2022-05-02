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


    int n,m;
    cin>>n>>m;
    int grid[n][m];
    memset(grid,0, sizeof grid);
    int already = 0;

    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();++j)
        {
            grid[i][j] = (s[j] == '#' ? 1 : 0);
            already += grid[i][j];
        }
    }

    int dist = 0;
    bool vis[n+1][m+1];
    memset(vis, false,sizeof vis);
    queue<pii> q;
    q.push({0,0});
    vis[0][0] = true;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};
    bool finish = false;
    while(!q.empty())
    {       
        int k = q.size();
        while(k--)
        {
            auto &p = q.front(); q.pop();
            if(p.f == n-1 && p.s == m-1)
            {
                finish = true;
                break;
            }

            for(int a=0;a<4;++a)
            {
                int x = p.f + dx[a], y = p.s + dy[a];
                if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 0)
                {
                    q.push({x,y});                  
                    vis[x][y] = true;
                }
            }
        }

        if(finish)
            break;
        dist++;
    }

    int ans = n*m - already - dist - 1;
    if(!finish)
        ans = -1;
    cout<<ans<<"\n";
}