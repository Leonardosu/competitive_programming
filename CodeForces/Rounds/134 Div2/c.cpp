#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool seen[N][N];
int matrix[N][N];

int n,ans;
int a,b;


void dfs(int x,int y)
{
	seen[x][y] = true;
	matrix[x][y] = 0;
	
	for(int i=x;i<N;++i)
	{
		if(matrix[i][y]) dfs(i,y);
		matrix[i][y] = 0;
	}

	for(int i=x;i>0;--i)
	{
		if(matrix[i][y]) dfs(i,y);
		matrix[i][y] = 0;
	}

	for(int i=y;i<N;++i)
	{
		if(matrix[x][i]) dfs(x,i);
		matrix[x][i] = 0;
	}
	for(int i=y;i>0;--i)
	{
		if(matrix[x][i]) dfs(x,i);
		matrix[x][i] = 0;
	}

}


int main()
{
	ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);


	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b;
		matrix[a][b] = 1;
	}

	for(int i=1;i<=1001;++i)
		for(int j=1;j<=1001;++j)
		{
			if(matrix[i][j] == 1)
			{
				dfs(i,j);
				ans++;
			}
		}

	cout<<ans - 1<<"\n";
}