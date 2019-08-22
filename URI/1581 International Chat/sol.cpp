/*		
	1581 - International Chat
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
set<string> data;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    
  cin>>TT;

  while(TT--)
  {
    cin>>n;
    getline(cin,frase); // limpar 
    data.clear(); maior=-1;

    for(int i=0;i<n;++i)
    {
      getline(cin,frase);
      data.insert(frase);
    }

    if(data.size()>1)
      cout<<"ingles\n";
    else
      cout<<frase<<"\n";

  }


  return 0;
}