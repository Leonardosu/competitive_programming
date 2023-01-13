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

int vis[3][3];
int alice[3][3], bob[3][3];
vector<pair<ll,ll>> score;
int inicio;
int win[3][3] = {
	0,2,1,
	1,0,2,
  	2,1,0};

void dfs(int x, int y) {
	int a = 0, b = 0;
	if(win[x][y] == 1) a++;
	if(win[x][y] == 2) b++;

	score.pb({a, b});

	int xx = alice[x][y];
	int yy = bob[x][y];
	if(vis[xx][yy] == -1) {
		vis[xx][yy] = vis[x][y] + 1;
		dfs(xx, yy);
	} else {
		inicio = vis[xx][yy];
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(vis, -1, sizeof vis);

    ll k, a, b;
    cin>>k>>a>>b;
    a--, b--;

    for(int i=0;i<3;++i)
    	for(int j=0;j<3;++j) {
    		cin>>alice[i][j];
    		alice[i][j]--;
    	}

    for(int i=0;i<3;++i)
    	for(int j=0;j<3;++j) {
    		cin>>bob[i][j];
    		bob[i][j]--;
    	}

    vis[a][b] = 0;
    dfs(a, b);

    a = 0, b = 0;
    for(int i=0;i<(int)score.size();++i) {
    	if(k<=0) {
    		break;
    	}
    	a += score[i].f, b += score[i].s;
    	k--;
    }

    if(k > 0) {
	    ll ciclo = score.size() - inicio;
	    ll mult = k / ciclo;
	    ll plus = k%ciclo;

	    for(int i=inicio;i<(int)score.size();++i) {
	    	a += score[i].f * mult;
	    	b += score[i].s * mult;

	    	if(plus-- > 0) {
	    		a += score[i].f;
	    		b += score[i].s;
	    	}
	    }    	
    }

    cout<<a<<" "<<b<<"\n";    
}