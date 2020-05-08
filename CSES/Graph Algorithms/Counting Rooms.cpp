#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef long long int ll;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int n,m,ans;
char data[N][N];

bool ok(int x,int y)
{
	if(x < 0 || x>=n || y < 0|| y>=m || data[x][y] == '#') return false;
	return true;
}

void dfs(int x,int y)
{
	data[x][y] = '#';

	for(int i=0;i<4;++i)
		if(ok(x+dx[i],y+dy[i]))
			dfs(x+dx[i],y+dy[i]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>data[i][j];
	
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(data[i][j] == '.')
				dfs(i,j),ans++;
	cout<<ans<<"\n";	
}