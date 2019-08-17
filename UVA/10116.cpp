#include <bits/stdc++.h>
#define MAXN 30
using namespace std;

char g[MAXN][MAXN];
int data[MAXN][MAXN];
int n,m,s,i,j,cont; // N,M=size s=X0 , i,j=pos , cont=passos
int tamloop,tamx; // tamanho do ciclo e passos até chegar no ciclo
bool cicle=false;

void update()
{
  char x=g[i][j];
  if(x=='W') j--;
  else if(x=='E') j++;
  else if(x=='S') i++;
  else if(x=='N') i--;

}

void solve(int a,int b)
{
    if(a<0 || a>=n || b<0 || b>=m) return;
    if(data[a][b]==2) {cicle=true; return;}

    data[a][b]++;
    cont++;
    update();
    a=i,b=j;
    solve(a,b);

}

void deu_ruim()
{
  int a,b;
  while(true)
  {
    a=i,b=j;
    if(data[a][b]==4) break;
    data[a][b]++;
    if(data[a][b]==2) tamx++;
    if(data[a][b]==3) tamloop++;
    update();
  }

}
int main()
{
  while(true)
  {
    cin>>n>>m>>s;
    if(n==0 && m==0 && s==0) return 0;
    memset(data,0,sizeof data);
    cicle=false; cont=0; i=0; j=s-1; tamloop=tamx=0;

    for(int a=0;a<n;++a)
        cin>>g[a];

    solve(0,j);
    if(!cicle) cout<<cont<<" step(s) to exit\n";
    
    else
    {
      i=0,j=s-1;
      deu_ruim();
      cout<<tamx<<" step(s) before a loop of "<<tamloop<<" step(s)\n";
    }


  }

  return 0;
}
