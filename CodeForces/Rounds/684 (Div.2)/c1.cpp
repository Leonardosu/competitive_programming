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

const int N = 100 + 7;
char grid[N][N];


void solve_task()
{
	int n, m;
	cin>>n>>m;

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>grid[i][j];


	vector<array<int, 6>> ans;
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			if(grid[i][j] == '0') continue;
			vector<pair<int,int>>cur;

			if(i+1<n) {
		    	cur.pb({i+1,j});
			    if(j+1<m){cur.pb({i,j+1});cur.pb({i+1,j+1});}
			    else {cur.pb({i,j-1});cur.pb({i+1,j-1});}
			} else {
			    cur.pb({i-1,j});
			    if(j+1<m){cur.pb({i,j+1});cur.pb({i-1,j+1});}
			    else {cur.pb({i,j-1});cur.pb({i-1,j-1});}
			}

			ans.pb({i,j,cur[0].f, cur[0].s, cur[1].f, cur[1].s});
		 	ans.pb({i,j,cur[0].f, cur[0].s, cur[2].f, cur[2].s});
		    ans.pb({i,j,cur[1].f, cur[1].s, cur[2].f, cur[2].s});		 
		}
	}

	cout<<ans.size()<<"\n";
	for(auto &q : ans) {
		for(int x : q)
			cout<<x+1<<" ";
		cout<<"\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}