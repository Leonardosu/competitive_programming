#include "bits/stdc++.h" // Treasure Island
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

typedef vector<vector<bool>> boolMatrix;
typedef vector<vector<int>> intMatrix;
int n, m;

map<pii, bool> visited;
bool canReach(boolMatrix &grid, int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m || !grid[x][y] || visited[{x,y}])
		return false;
	if(x == n-1 && y == m-1)
		return true;
	visited[{x,y}] = true;
	return canReach(grid, x+1, y) || canReach(grid, x, y+1);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;

	boolMatrix grid(n, vector<bool>(m));

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			char c;
			cin>>c;
			grid[i][j] = (c == '.');
		}

	int qnt = 0;
	if(canReach(grid, 0, 0))
	{
		visited[{0, 0}] = visited[{n-1, m-1}] = false;
		qnt = 1 + canReach(grid, 0, 0);
	}
	cout<<qnt<<"\n";
	
}