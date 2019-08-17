#include <bits/stdc++.h>
#define MAXN 90
using namespace std;
string data[35];

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int t,x,y,tam;

void floodfill(int a,int b,char K)
{
    if(a<0 || b<0 || data[a][b]!=' ' || a>=tam || b>=data[a].size() ) return;
    data[a][b]=K;
    for(int i=0;i<4;++i)
        floodfill(a+dx[i],b+dy[i]);
    return ;
}


int main()
{
    //ios_base::sync_with_stdio(false); //cin.tie(0);
    cin>>t;
    getline(cin,data[0]);

    for(int z=1;z<=t;++z)
    {
      tam=0;
      bool ok=true;

      while(ok)
      {
        getline(cin,data[tam]);
        ok=false;

        for(int i=0;i<data[tam].size();++i)
          if(data[tam][i]!='_')
          {
            ok=true;
            if(data[tam][i]=='*') x=tam,y=i;
          }
        tam++;
      }

      data[x][y]=' ';
      floodfill(x,y);
      for(int i=0;i<tam;++i)
        cout<<data[i]<<'\n';
    }


    return 0;
}

