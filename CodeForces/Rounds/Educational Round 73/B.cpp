#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define BLACK 1
#define WHITE 0
using namespace std;
 
const int N = 110;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
int dx[]={2,2,1,1,-2,-2,-1,-1};
int dy[]={-1,1,-2,2,-1,1,-2,2};
int n;
 
char chess[N][N];
bool visited[N][N];
 
bool check(int i,int j)
{
	if(i<0 || j<0 || i>n || j>n ) return false;
	return true;
}
 
void dfs(int i,int j,int tipo)
{
	visited[i][j] = true;
	if(tipo == BLACK) chess[i][j] = 'B';
	else chess[i][j] = 'W';
 
	int xx,yy;
	for(int z = 0;z<8;++z)
	{
		xx = dx[z] + i; yy = dy[z] + j;
		if(check(xx,yy) && !visited[xx][yy])
			dfs(xx,yy,(tipo+1)%2);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>n;
	dfs(0,0,0);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			cout<<chess[i][j];
		cout<<"\n";
	}
}