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
mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 507;
int grid[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;++i) {
    	for(int j=0;j<m;++j)
    		cin>>grid[i][j];
    }

   	vector<array<int, 4>> ans; 
   	for(int i=0;i<n;++i) {
   		for(int j=0;j+1<m;++j) {
   			if(grid[i][j]&1) {
   				grid[i][j]--;
   				grid[i][j+1]++;
   				ans.pb({i,j,i,j+1});
   			}
   		}
   	}

   	int j=m-1;
   	for(int i=0;i+1<n;++i) {
		if(grid[i][j]&1) {
			grid[i][j]--;
			grid[i+1][j]++;
			ans.pb({i,j,i+1,j});
		}
	}

   	cout<<sz(ans)<<endl;
   	for(auto [a, b, c, d] : ans) {
   		cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
   	}

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}