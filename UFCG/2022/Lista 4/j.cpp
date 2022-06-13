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

	int grid[n+1][m+1];
	for(int i=1;i<=n;++i, cout<<"\n")	
		for(int j=1;j<=m;++j)
		{	
			cin>>grid[i][j];
			int sum = i + j;
			if(sum%2 == 1 && grid[i][j]%2 == 0)
				grid[i][j]++;			
			else if(sum%2 == 0 && grid[i][j]%2 == 1)
				grid[i][j]++;
		
			cout<<grid[i][j]<<" ";
		}
	// cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}