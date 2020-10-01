#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 1e9;
const int maxn = 10100;
int N, M, Q, K;

struct Estado
{
    int T, C, u;
  
    Estado(int t = 0, int c = 0, int u = 0) : T(t), C(c), u(u) {}

    bool operator < (const Estado &a) const
    {
        return T != a.T ? T > a.T : C > a.C;
    }
};

struct Grafo
{
    vector<ii> grafo[maxn];

    void add(int u, int v, int c)
    {
        grafo[u].pb({v, c});
    }
  
    vector<vi> Dijkstra(int origem)
    {
        priority_queue<Estado> pq;
        vector<vi> dist(N);

        for(int i = 0; i < N; i++)
            for(int j = 0; j <= K; j++)
                dist[i].pb(INF);

        dist[origem][0] = 0;

        pq.push(Estado(0, 0, origem));

        while(!pq.empty())
        {
            auto atual = pq.top();            
            pq.pop();
            
            int u = atual.u;
            int C = atual.C;
            int T = atual.T;
            
            
            for(auto x : grafo[u])
            {
                int v = x.first;
                int c = x.second;
                
                if(dist[v][T] > C + c)
                    pq.push(Estado(T, dist[v][T] = C + c, v));
                    
                if(T < K)
                    if(dist[v][T + 1] > C)
                        pq.push(Estado(T + 1, dist[v][T + 1] = C, v));
            }
        }

        for(int i = 0; i < N; i++)
            for(int j = 1; j <= K; j++)
                dist[i][j] = min(dist[i][j], dist[i][j - 1]);

        return dist;
    }

};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
    Grafo normal, reverso;
    
    int A, B;
    
    cin>>N>>M>>A>>B>>K;
    
    int u, v, c;
    
    while(M--)
    {
        cin>>u>>v>>c;
        
        normal.add(u, v, c);
        reverso.add(v, u, c);
    }
    
    
    auto x = normal.Dijkstra(A);
    auto y = normal.Dijkstra(B);
    
    auto z = reverso.Dijkstra(A);
    auto w = reverso.Dijkstra(B);
  
    ii ans(INF, INF);
    
    for(int i = 0; i < N; i++)
    {
        if(i == A || i == B) continue;
        
        int custoA = INF,custoB = INF;
        for(int j=0;j<=K;++j)
        {
            custoA = min(x[i][j] + z[i][K-j],custoA);
            custoB = min(y[i][j] + w[i][K-j],custoB);
        }
        
        ans = min(ans, ii(custoA + custoB, i));
    }
    
    if(ans.first == INF) cout<<">:(\n";
    else cout<<ans.second<<" "<<ans.first<<"\n"; 
    
	return 0;
}