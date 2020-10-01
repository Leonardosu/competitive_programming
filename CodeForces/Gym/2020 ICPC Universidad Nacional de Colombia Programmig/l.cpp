#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 2110;

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
// DLRU
string dir = "DLRU";
int n,m;
char ww[maxn][maxn];
int dist[maxn][maxn],vim[maxn][maxn];
ii prox[maxn][maxn][4], coluna[maxn];
// muita memoria T-T

inline int convert(int x){ return 3 - x;}
inline bool check(ii a)
{
    if(a.x < 1 || a.x > n || a.y < 1 || a.y > m) return false;
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m;
    ii ini,fim;
    memset(dist,-1,sizeof(dist));
    memset(vim,-1,sizeof(vim));


    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            for(int k=0;k<4;++k)
                prox[i][j][k] = {-1,-1};

            cin>>ww[i][j];
            if(ww[i][j] == 'S') ini = {i,j};
            if(ww[i][j] == 'E') fim = {i,j};
        }
    

    for(int i=1;i<=m;++i) coluna[i] = {-1,-1};

    for(int i=1;i<=n;++i)
    {
        ii last = {-1,-1};
        for(int j=1;j<=m;++j)
        {            
            if(ww[i][j] == 'X') continue;
            // int dx[] = {1,0,0,-1};
            // int dy[] = {0,-1,1,0};
            // // DLRU
            if(coluna[j].y != -1)
                prox[coluna[j].x][coluna[j].y][0] = {i,j};                        
            if(last.y != -1)
                prox[last.x][last.y][2] = {i,j};
            
            prox[i][j][1] = last;
            prox[i][j][3] = coluna[j];

            last = coluna[j] = {i,j};
        }
    }

    // swap(ini,fim);
    queue<ii> fila;
    fila.push(fim);
    dist[fim.x][fim.y] = 0;

    while(!fila.empty())
    {
        ii now = fila.front();
        fila.pop();
        if(now == ini) break;

        for(int k=0;k<4;++k)
        {
            int xx = prox[now.x][now.y][k].x, yy = prox[now.x][now.y][k].y;
            if( xx == -1 || dist[xx][yy] != -1) continue;
            fila.push({xx,yy});
            dist[xx][yy] = dist[now.x][now.y] + 1;
            vim[xx][yy] = convert(k);
        }
    }


    if(dist[ini.x][ini.y] == -1)
    {
        cout<<"-1\n";
        return 0;
    }

    ii now = ini;
    string ans = "";
    while(now != fim)
    {
        for(int k=0;k<4;++k)
        {
            int xx = prox[now.x][now.y][k].x, yy = prox[now.x][now.y][k].y;
            if(xx != -1 && dist[xx][yy] + 1 == dist[now.x][now.y])
            {
                ans.pb(dir[k]);
                now = prox[now.x][now.y][k];
                break;
            }
        }

        if(now == fim) break;
    }

    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";
}