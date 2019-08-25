/*
	1025 - Where is the Marble?
	Leonardo Su
*/
#include <bits/stdc++.h>
#define MAXN 10100 
using namespace std;

int n,m,ttt;
int a,b;
int data[MAXN];

int buscab(int x)
{
  int ini=1,fim=n,meio;
  
  while(ini<=fim)
  {
    meio=(ini+fim)/2;
    
    if(data[meio]==x)
    {
      while(true)
      {
       if(data[meio]!=x) break;
       
       meio-=1;
      }
      return meio+1;
    }
    if(data[meio]>x) fim=meio-1;
    if(data[meio]<x) ini=meio+1;
    //cout<<">>>"<<meio<<"\n";
    
  }
  
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  while(cin>>n>>m && (n+m))
  {
    ttt++;
    cout<<"CASE# "<<ttt<<":\n";
    
    for(int i=1;i<=n;++i)
      cin>>data[i];
      
    sort(data+1,data+n+1);
    
    for(int i=1;i<=m;++i)
    {
      cin>>a;
      b=buscab(a);
      if(b!=-1)
        cout<<a<<" found at "<<b<<"\n";
      else
        cout<<a<<" not found\n";
    }
    
  }
    
  return 0;
}