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

const int N = 101;
int grid[N][N];
int n, m;

vector<array<int,4>> ops;

void solve(int x, int y)
{
	if(x < 0 || y < 0)
		return ;

	if(grid[x][y] == 1)
	{
		if (x != 0) 
            ops.push_back({x, y + 1, x + 1, y + 1});
        else
            ops.push_back({x + 1, y, x + 1, y + 1});
	}

	if(y == 0)
		solve(x-1,m-1);
	else
		solve(x,y-1);
}

void solve_task()
{
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;++j)
			grid[i][j] = s[j] - '0';
	}

	if(grid[0][0] == 1)
		cout<<"-1\n";
	else
	{
		solve(n-1,m-1);
		cout<<ops.size()<<"\n";
		for(auto &op : ops)
		{
			for(int &x : op)
				cout<<x<<" ";
			cout<<"\n";
		}
		ops.clear();
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}