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

void solve_task()
{
	int n, m;
	cin>>n>>m;
	n<<=1;
	n++;
	m<<=1;
	m++;

	char grid[n][m];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			grid[i][j] = '.';
			if(i&1 && !(j&1))
				grid[i][j] = '|';
			else if(!(i&1))
			{
				if(!(j&1))
					grid[i][j] = '+';
				else
					grid[i][j] = '-';
			}
		}
	grid[0][0] = grid[0][1] = grid[1][0] = '.';
	for(int i=0;i<n;++i, cout<<"\n")
		for(int j=0;j<m;++j)
			cout<<grid[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	for(int TTT=1;TTT<=T_T;++TTT)
	{
		cout<<"Case #"<<TTT<<":\n";
		solve_task();
	}
}