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

void solve_task()
{
	int n, m;
    cin>>n>>m;
    
    vector<int> g[n];
    vi adj(n), dist(n);
    bool visited[n]; memset(visited, false, sizeof visited);

    const int inf = 2e9;
    for(int &x : dist)
        x = inf;

    for(int i=0;i<m;++i) {
        int a, b;
        cin>>a>>b;
        a--, b--;

        g[b].pb(a);
        adj[a]++;
    }

    priority_queue<pii, vector<pii>, greater<pii>> nodes;
    dist[n-1] = 0;
    nodes.push({0, n-1});

    while(!nodes.empty()) {
        auto [d, x] = nodes.top(); nodes.pop();
        if(visited[x]) continue;        
        visited[x] = true;
        for(int &y : g[x]) {
            if(d + adj[y] < dist[y]) {
                dist[y] = d + adj[y];
                nodes.push({dist[y], y});
            }
            adj[y]--;
        }
    }

    cout<<dist[0]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    // cin>>T_T;
    while(T_T--)
        solve_task();
}