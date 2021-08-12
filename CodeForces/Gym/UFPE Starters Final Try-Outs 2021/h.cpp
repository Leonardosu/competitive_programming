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

const int n = 3;

inline int genState(vector<vector<int>> &mat)
{
	int s = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			s = 10*s + mat[i][j];

	return s;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	vector<vector<int>> mat(3,vector<int>(3));
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{			
			cin>>mat[i][j];
			if(mat[i][j] == 0)
				mat[i][j] = 9;
		}

	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

	ll custo[9];
	for(int i=1;i<=8;++i)
		cin>>custo[i];

	priority_queue< pair<ll,int> , vector<pair<ll,int>>, greater<pair<ll,int>>> fila;
	fila.push({0,genState(mat)});

	int fim = 123456789;

	unordered_map<int,ll> dist;
	unordered_set<int> vis;

	while(!fila.empty())
	{
		int curr = fila.top().s;
		ll d = fila.top().f;

		fila.pop();
		if(curr == fim)
		{
			cout<<d<<'\n';
			return 0;
		}

		if(vis.count(curr))
			continue;
		vis.insert(curr);

		int x,y;
		int aux = curr;

		for(int i=2;i>=0;--i)
			for(int j=2;j>=0;--j)
			{
				mat[i][j] = aux%10;			
				aux/=10;

				if(mat[i][j] == 9)
					x = i,y = j;
			}
	
		
		for(int k=0;k<4;++k)
		{
			int xx = x + dx[k], yy = y + dy[k];
			if(xx >=0 && xx < n && yy >= 0 && yy < n)
			{
				// cout<<"??????????\n";
				ll dd = custo[mat[xx][yy]];

				swap(mat[xx][yy],mat[x][y]);

				int estado = genState(mat);

				if(!dist.count(estado) || dist[estado] > d + dd)
					dist[estado] = d + dd, fila.push({dist[estado],estado});
				swap(mat[xx][yy],mat[x][y]);
			}
		}

	}



}