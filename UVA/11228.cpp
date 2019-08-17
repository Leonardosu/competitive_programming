/*
  *********************
  uva 11228 Transportation system
  Leonardo Su
*/

#include <bits/stdc++.h>
#define MAXN 1010
#define C first
#define X second.first
#define Y second.second
#define mp make_pair
using namespace std;

int pai[MAXN],peso[MAXN],state[MAXN],peso_s[MAXN];
int n,m,t,ttt;
double custo1,custo2,dmax;
bool ja_foi[MAXN];
typedef pair<int,int> ii;
typedef pair<double,ii> dii;
vector<dii> grafo;

struct point
{
    double x,y;
};

int achar(int x,int v[])
{
    if(x==v[x])return x;
    return v[x]=achar(v[x],v);
}

void join(int x,int y,int v[],int p[])
{
    x=achar(x,v);
    y=achar(y,v);
    if(x==y) return;
    if(p[x]<p[y]) v[x]=y;
    if(p[x]>p[y]) v[y]=x;
    else
    {
        v[x]=y;
        p[y]++;
    }
    return ;
}

double dist(point a,point b)
{
    return sqrt( pow(a.x-b.x,2) + pow(a.y-b.y,2) );
}

point vtx[MAXN];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    while(cin>>t)
    {
        if(ttt!=0) cout<<"\n";
        ttt++;
        
        for(int z=1;z<=t;++z)
        {
            custo1=0; custo2=0; grafo.clear();
            cin>>n>>dmax;

            for(int i=1;i<=n;++i)
            {
                cin>>vtx[i].x>>vtx[i].y;
                pai[i]=i; peso[i]=0;
                state[i]=i; peso_s[i]=0;
                ja_foi[i]=false;
            }

            for(int i=1;i<=n;++i)
                for(int j=i+1;j<=n;++j)
            {
                double d=dist(vtx[i],vtx[j]);
                if(d<=dmax)
                    join(i,j,state,peso_s);
                grafo.push_back(mp(d,mp(i,j)));
                grafo.push_back(mp(d,mp(j,i)));
            }

            sort(grafo.begin(),grafo.end());

            for(int i=0;i<grafo.size();++i)
            {
                pair<double,ii> atual=grafo[i];
                if(achar(atual.X,pai) != achar(atual.Y,pai))
                {
                    if(atual.C<=dmax)
                        custo1+=atual.C;
                    else if(atual.C>=dmax)
                        custo2+=atual.C;

                    join(atual.X,atual.Y,pai,peso);
                }

            }

            int qnt_set=0;
            for(int i=1;i<=n;++i)
                if(!ja_foi[achar(i,state)]) {qnt_set++; ja_foi[achar(i,state)]=true;}

            cout<<"Case #"<<z<<": "<<qnt_set<<' '<<(int)(custo1+0.5)<<' '<<(int)(custo2+0.5)<<'\n';
        }

    }

    return 0;
}
