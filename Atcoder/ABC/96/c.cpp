#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
const int N = 52;
char mat[N][N];
bool valid(int x,int y)
{
	return (x >= 0 && x<n && y>=0 && y<m);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>mat[i][j];

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{

			if(mat[i][j] == '#')
			{
				bool find = false;
				for(int k=0;k<4;++k)
				{
					int xx = i + dx[k],yy = j + dy[k];
					if(valid(xx,yy) && mat[xx][yy] == '#')
					{
						find = true;
						break;
					}
				}
				if(!find)
				{
					cout<<"No\n";
					return 0;
				}
			}
		}

	cout<<"Yes\n";
}