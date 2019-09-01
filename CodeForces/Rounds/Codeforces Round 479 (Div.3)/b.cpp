#include <bits/stdc++.h>
using namespace std;
 
int n,ans,id,x;
int v[3000];
char atual,anterior,a,b;
 
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
 
  cin>>n;
  cin>>anterior;
 
  for(int i=1;i<n;++i)
  {
    cin>>atual;
    x = (anterior - 'A')*100 + (atual - 'A');
    v[x]++;
    if(v[x]>ans) ans = v[x],a = anterior,b = atual;
    anterior = atual;
  }
 
  cout<<a<<b<<"\n";
 
}