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

const int N = 1e3 + 7;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int n, m, p, total;
char grid[N][N];
int places[10], speed[10];
int dist[N][N];

vector<queue<pii>> filas(10);

int ceil(int a, int b) {
	return (a+b-1)/b;
}

inline bool inside(int i, int j) {
	return (1<=i&&i<=n && 1<=j&&j<=m);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof dist);
    cin>>n>>m>>p;
    for(int i=1;i<=p;++i)
    	cin>>speed[i];

    
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=m;++j) {
    		cin>>grid[i][j];
    		char c = grid[i][j];

    		if('1'<=c&&c<='9') {
    			dist[i][j] = 0;
    			places[c-'0']++;
    			filas[c-'0'].push({i,j});
    		}
    	}

    vi v;
    for(int i=1;i<=p;++i)
    	if(!filas[i].empty())
    		v.pb(i);

    int turn = 1;
    while(turn <= n*m) {
    	// cout<<turn<<": "<<v.size()<<"\n";
    	for(int &id : v) {
			while(!filas[id].empty()) {
				auto [x, y] = filas[id].front();
				if(ceil(dist[x][y] + 1, speed[id]) > turn) break;
				 filas[id].pop();

				for(int k=0;k<4;++k) {
					int xx = x + dx[k], yy = y + dy[k];

					if(inside(xx, yy) && grid[xx][yy] != '#' && dist[xx][yy] == -1) {
						dist[xx][yy] = dist[x][y] + 1;
						places[id]++;
						filas[id].push({xx,yy});
					}
				}
			}
    		
    	}

    	turn++;	
    	auto aux = v;
    	v.clear();
    	for(int &x : aux)
    		if(!filas[x].empty())
    			v.pb(x);

    	// if(v.empty()) break;
    }

    for(int i=1;i<=p;++i)
    	cout<<places[i]<<" ";
    cout<<"\n";
}