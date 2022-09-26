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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int mat[3][3];
    memset(mat, 0, sizeof mat);
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    int n = 3;
    for(int i=0;i<n;++i)
    	for(int j=0;j<n;++j) {
    		int moves;
    		cin>>moves;
    		mat[i][j] += moves + 1;
    		for(int k=0;k<4;++k) {
    			int x = i + dx[k], y = j + dy[k];

    			if(x>=0 && x<n && y>=0 && y<n) {
    				mat[x][y] += moves;
    			}
    		}

    		
    	}

    for(int i=0;i<n;++i,cout<<"\n")
    	for(int j=0;j<n;++j)
    		cout<<mat[i][j]%2;
    cout<<"\n";
}