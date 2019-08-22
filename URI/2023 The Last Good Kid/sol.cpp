/*						
	2023 - The Last Good Kid
	Leonardo Su 		
	5/19/17, 8:01:38 PM
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
priority_queue<string> fila;
map<string,string> data;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    

  while(getline(cin,frase))
  {
    if(frase[0]=='\n')
      break;
    string k;

    for(int i=0;i<frase.size();++i)
      if(isalpha(frase[i]))
        k+=tolower(frase[i]);

    data[k]=frase;
    fila.pb(k);
    //cout<<"\n teste  "<<k<<" \n";
  }

  cout<<data[fila.top()]<<"\n";

  return 0;
}