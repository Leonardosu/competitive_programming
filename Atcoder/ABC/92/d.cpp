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

    int a,b, n = 100;
    cin>>a>>b;

    char grid[n+1][n+1];
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;j++)
    		grid[i][j] = (j > 50 ? '.' : '#');
    }
	
	for(int i=1;i<=n;i+=2)
		for(int j=1;j<50;++j)
			if((i+j)%2 && (a!=1))
				grid[i][j] = '.', a--;

	for(int i=1;i<=n;i+=2)    
		for(int j=51;j<=n;++j)
			if((i+j)%2 && (b!=1))
				grid[i][j] = '#', b--;

	cout<<n<<" "<<n<<"\n";
	for(int i=1;i<=n;++i, cout<<"\n")
		for(int j=1;j<=n;++j)
			cout<<grid[i][j];
}