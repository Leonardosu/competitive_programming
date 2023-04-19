#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[] = {0,1,-1,0,1,-1,-1,1};
int dy[] = {1,0,0,-1,1,-1,1,-1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    char grid[n+2][m+2];

    for(int i=0;i<n+2;++i)
    	for(int j=0;j<m+2;++j)
    		grid[i][j] = '!';

    for(int i=1;i<=n;++i)
    	for(int j=1;j<=m;++j)
    		cin>>grid[i][j];

    for(int i=1;i<=n;++i, cout<<"\n")
    	for(int j=1;j<=m;++j) {
    		if(grid[i][j] == '#')
    			cout<<"#";
    		else {
    			int qnt = 0;
	    		for(int k=0;k<8;++k) {
	    			if(grid[i+dx[k]][j+dy[k]] =='#')
	    				qnt++;
	    		}

    		cout<<qnt;
    		}
    		
    	}
}