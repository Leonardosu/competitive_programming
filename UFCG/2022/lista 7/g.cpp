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

const int N = 4e5 + 7;
vi g[N];
map<int,int> m[N];

int v[N], ans;
bool comp[N], process[N];

void crivo() {
	for(int i=2;i<N;++i) 
		if(!comp[i]){
			for(int j=2*i;j<N;j+=i)
				comp[j] = true;
		}
}

int dfs(int x) {
	process[x] = true;

	int r = 0;
	for(int i = 1;i <= sqrt(v[x]);i++){
		if(v[x] % i == 0){
			if(comp[i] == false) 
				m[x][i] += 1 , r = 1 ;

			if(comp[v[x]/i] == false && v[x]/i != i) 
				m[x][v[x]/i] += 1 , r = 1 ;
		} 
	}

	for(int i=0;i<(int)g[x].size();++i) {
		int nxt = g[x][i];
		if(process[nxt]) continue;

		r = max(r, dfs(nxt));

		for(auto j : m[x]) {
			if(m[nxt].find(j.f) == m[nxt].end()) continue;

			r = max(r, m[x][j.f] + m[nxt][j.f]);
			m[x][j.f] = max(m[x][j.f], m[nxt][j.f] + 1);
		}
	}

	return r;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(comp, false, sizeof comp);
    memset(process, false, sizeof process);

    ans = 0;
    comp[1] = true;
    crivo();


    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    	cin>>v[i];

    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    cout<<dfs(1)<<"\n";
}