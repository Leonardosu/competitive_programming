/*		
	1273 - Justifier
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 120
#define pb push
#define mp make_pair
using namespace std;

string frase,resp;
int n,maior,TT;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    

  while(cin>>n && n)
  {
    if(TT!=0)
      cout<<"\n";
    TT++;
    queue<string> fila; maior=-1;
    getline(cin,frase);
    for(int i=0;i<n;++i)
    {
      getline(cin,frase);
      fila.pb(frase);
      maior=max(maior,(int)frase.size());
    }

    for(int i=0;i<n;++i)
    {
      resp=fila.front();
      fila.pop();
      cout<<setw(maior);
      cout<<resp<<"\n";
    }

  }


  return 0;
}