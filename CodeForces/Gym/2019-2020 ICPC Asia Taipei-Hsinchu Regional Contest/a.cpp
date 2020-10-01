#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
const int maxn = 7;
const int inf = 1;
const int mod = 1e9 + 7;
const int prim = 31;

set<string> estados;
int n = 6,qnt;
int mat[7][7];

struct carro
{    
    int lx,rx,ly,ry;    
    bool vertical;
    carro()
    {
        lx = ly = 1e9;
        rx = ry = 0;
    }
} c[18];

struct T //estado
{
    int m[7][7];
};

string pick(T mat)
{
    string ans = "";
    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            ans.pb(mat.m[i][j] + 'a');
            
    return ans;
}

void go(T mat)
{
    for(int i=1;i<=qnt;++i) c[i] = carro();
    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            int now = mat.m[i][j];
            c[now].lx = min(c[now].lx,i);
            c[now].rx = max(c[now].rx,i);

            c[now].ly = min(c[now].ly,j);
            c[now].ry = max(c[now].ry,j);

            if(c[now].lx == c[now].rx) c[now].vertical = false;
            if(c[now].ly == c[now].ry) c[now].vertical = true;
        }

}

int solve(T init)
{
    queue< pair<int,T> > fila;
    fila.push({0,init});

    while(!fila.empty())
    {
        int move = fila.front().f;

        if(move > 8) 
            return -1;
            
        T aux = fila.front().s;
        fila.pop();
        if(aux.m[2][5] == 1)
            return move + 2;

        string value = pick(aux);
        if(estados.count(value)) continue;
        estados.insert(value);

        go(aux);//atualizar as pos dos carros        
        for(int i=1;i<=qnt;++i)
        {
            if(c[i].vertical)
            {
                int lx = c[i].lx, rx = c[i].rx;
                int y = c[i].ly;
                
                if(rx + 1 < n && aux.m[rx+1][y] == 0) //x++
                {
                    aux.m[rx+1][y] = i,aux.m[lx][y] = 0;
                    fila.push({move+1,aux});
                    aux.m[rx+1][y] = 0,aux.m[lx][y] = i;
                }
                if(lx > 0 && aux.m[lx-1][y] == 0)//x--
                {
                    aux.m[lx-1][y] = i,aux.m[rx][y] = 0;
                    fila.push({move+1,aux});
                    aux.m[lx-1][y] = 0,aux.m[rx][y] = i;
                }
            }
            else
            {
                int ly = c[i].ly,ry = c[i].ry;
                int x = c[i].lx;
                
                if(ry + 1 < n && aux.m[x][ry+1] == 0)//y++
                {
                    aux.m[x][ry + 1] = i,aux.m[x][ly] = 0;
                    fila.push({move+1,aux});
                    aux.m[x][ry + 1] = 0,aux.m[x][ly] = i;
                }
                if(ly > 0 && aux.m[x][ly-1] == 0)//y--
                {
                    aux.m[x][ly - 1] = i,aux.m[x][ry] = 0;
                    fila.push({move+1,aux});
                    aux.m[x][ly - 1] = 0,aux.m[x][ry] = i;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            cin>>mat[i][j];
            qnt = max(mat[i][j],qnt);
        }

    T aux;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            aux.m[i][j] = mat[i][j];

    go(aux);
    cout<<solve(aux)<<"\n";    
}