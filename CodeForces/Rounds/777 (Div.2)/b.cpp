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

int n,m;
bool valid(int x, int y)
{
	return (0<=x && x<n && 0<=y && y<m);
}

void solve_task()
{
	cin>>n>>m;

	char grid[n+1][m+1];
	memset(grid,0,sizeof(grid));

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>grid[i][j];
	
	int dx[] = {0,1,0,1};
	int dy[] = {0,0,1,1};

	bool solo = false;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			int ones = 0;
			for(int k=0;k<4;++k)
			{
				int x = i + dx[k], y = j + dy[k];
				if(valid(x,y))
				{
					if(grid[x][y]=='1')
						ones++;
				}
			}

			if(ones == 3)
			{
				solo = true;
				break;
			}
		}

	cout<<(solo ? "NO" : "YES")<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}