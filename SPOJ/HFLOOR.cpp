/*
	HFLOOR SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define pb push_back
#define N 110
using namespace std;

char mat[N][N];
bool vis[N][N];

double media;
int t,n,m,total,quartos;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool check(int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=m || mat[i][j] == '#') return false;
	return true;
}

int dfs(int i,int j)
{
	if(vis[i][j]) return 0;
	vis[i][j] = true;
	
	int sum = 0;

	if(mat[i][j] == '*') sum++;

	for(int k=0;k<4;++k)
		if(check(i + dx[k],j + dy[k]))
			sum+=dfs(i + dx[k],j + dy[k]);
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;

	while(t--)
	{
		cin>>n>>m; total = quartos = 0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin>>mat[i][j],vis[i][j]=false;

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(!vis[i][j] && mat[i][j]!='#')
					total+=dfs(i,j),quartos++;

		media=(double)total/quartos;
		cout<<fixed<<setprecision(2);
		cout<<media<<"\n";
	}
}