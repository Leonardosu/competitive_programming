/*						
	2137 - The Library of Mr. Severino
	Leonardo Su 		
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 120
#define pb push
#define mp make_pair
#define T string
using namespace std;

string frase,resp;
int n,maior,TT;
priority_queue<T, vector<T> , greater<T> > fila;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    

  while(cin>>n)
  {
    getline(cin,frase);

    for(int i=0;i<n;++i)
    {
      getline(cin,frase);
      fila.pb(frase);
    }

    while(!fila.empty())
      {
        cout<<fila.top()<<"\n";
        fila.pop();
      }
  }


  return 0;
}