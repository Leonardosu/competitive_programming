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
 
void add_edge(vector<pii> adj[], int src, int dest, int c)
{
    adj[src].push_back({dest, c});
    adj[dest].push_back({src, c});
}

vector<pair<vector<int>, int>>paths;
int shortestPath = INT_MAX;
int n, m;

void find_paths(vector<int>& path, vector<pii> parent[], int u, int cost)
{
    if (u == -1) 
    {
        int len = path.size();
        if(len < shortestPath)
            shortestPath = len, paths.clear();

        paths.push_back({path, cost});
        return;
    }
 
    for (auto &[par, good] : parent[u]) {
        path.push_back(u);
        find_paths(path, parent, par, cost + good);
        path.pop_back();
    }
}
 
void bfs(vector<pii> adj[], vector<pii> parent[], int start)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
 
    q.push(start);
    parent[start] = {{-1,0}};
    dist[start] = 0;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &[v, good] : adj[u]) {
            if (dist[v] > dist[u] + 1) {
 
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();

                parent[v].push_back({u,good});
            }
            else if (dist[v] == dist[u] + 1) 
                parent[v].push_back({u, good});           
        }
    }
}
 
int Goods = 0;
vector<array<int,3>> edges;
int QUEBRAR = 0;
int CONSERTAR = 1;

void solve(vector<pii> adj[], int start, int end)
{
    vector<int> path;
    vector<pii> parent[n];
 
    bfs(adj, parent, start);
    find_paths(path, parent, end, 0);
    
    int best = INT_MAX;
    int i = 0, id = 0;

    for (auto &[v, cost] : paths) {
        reverse(v.begin(), v.end());
 
        // for (int u : v)
            // cout << u << " ";
        int qnt = Goods - cost + (shortestPath -1 - cost);

        //todo mundo bom - bons no meu caminho 
        // + quebrado do meu caminho
        // cout << qnt << endl;
        if(qnt < best)
            id = i, best = qnt;
        i++;
    }
    
    set<pair<int,int>> caras;
    for(int i=1;i<paths[id].f.size();++i)
    {
        int x = paths[id].f[i-1], y = paths[id].f[i];
        caras.insert({x,y});
        caras.insert({y,x});
    }

    cout<<best<<"\n";
    for(auto &edge: edges)
    {
        if(caras.find({edge[0],edge[1]}) != caras.end())
        {
            if(edge[2] == 0)
                cout<<edge[0]<<" "<<edge[1]<<" "<<CONSERTAR<<"\n";
        }
        else if(edge[2] == 1)
            cout<<edge[0]<<" "<<edge[1]<<" "<<QUEBRAR<<"\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n>>m;
    n++;

    vector<pii> adj[n+1];
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        Goods += c;
        add_edge(adj, a, b, c);
        edges.pb({a,b,c});
    }

    int src = 1, dest = n-1;
    solve(adj, src, dest);
 
    return 0;
}