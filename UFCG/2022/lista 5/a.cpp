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

	int n, k;
	cin>>n>>k;
	
	int degree[n];
	for(int i=0;i<n;++i) 
		degree[i] = k;

	vector<int> dist[n];
	vector<pii> edges;

	for(int i=0;i<n;++i) {
		int x;
		cin>>x;
		dist[x].pb(i);
	}


	bool possible = false;
	if(dist[0].size() == 1) {
		possible = true;
		for(int d=1;d<n && possible;++d) {
			if(dist[d-1].size() * k < dist[d].size()) {
				possible = false;
			}


			if(!possible || dist[d].empty()) break;

			int id = 0;
			for(int &x : dist[d]) {
				while(id < dist[d-1].size() && degree[dist[d-1][id]] == 0)
					id++;
				if(id == dist[d-1].size() || degree[dist[d-1][id]] == 0) {
					possible = false;
					break;
				}

				int y = dist[d-1][id];
				degree[x]--, degree[y]--;
				edges.pb({y+1, x+1});
			}
		}
		
		if(edges.size() != n - 1)
			possible = false;
	}
	
	if(possible) {
		cout<<edges.size()<<"\n";
		for(auto &[x, y] : edges)
			cout<<x<<" "<<y<<"\n";
	} else {
		cout<<"-1\n";
	}

}