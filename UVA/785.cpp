#include <bits/stdc++.h>
#define MAXN 90
using namespace std;
string data[MAXN];

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int t,x,y,tam,TT;

void solve(int a,int b,char x)
{
  if(a<0 || b<0 || data[a][b]!=' ' || a>=tam || b>=data[a].size() ) return;
  data[a][b]=x;
  for(int i=0;i<4;++i)
    solve(a+dx[i],b+dy[i],x);
}


int main()
{
    //ios_base::sync_with_stdio(false); //cin.tie(0);

    while(true)
    {
      tam=0;
      if( ! getline(cin,data[0]) ) return 0;
      if(TT!=0) cout<<'\n';

      bool ok=true; tam++;
      while(ok)
      {
        getline(cin,data[tam]);
        ok=false;

        for(int i=0;i<data[tam].size();++i)
          if(data[tam][i]!='_') { ok=true;  }

        tam++;
      }

      for(int i=0;i<tam-1;++i)
        for(int j=0;j<data[i].size();++j)
        {
          if(data[i][j]!=' ' && data[i][j]!='X')
          {
            char c=data[i][j];
            data[i][j]=' ';
            solve(i,j,c);
          }
        }

      for(int i=0;i<tam;++i)
        {
          if(i==tam-1)
            cout<<data[i];

          else
          cout<<data[i]<<'\n';
        }

      TT++;
    }

    return 0;
}