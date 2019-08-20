/*	
	1255 - Letter Frequency
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 120
#define mp make_pair
using namespace std;

string frase,k;
int n;
typedef pair<int,char> ic;
map<char,int> data;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    

  cin>>n;
  getline(cin,frase);

  for(int a=0;a<n;++a)
  {
    getline(cin,frase); 
    k.clear(); data.clear();

    priority_queue<ic , vector<ic> , greater<ic> > fila;

    for(int i=0;i<frase.size();++i)
      if(isalpha(frase[i]))
        data[tolower(frase[i])]++;

    for(map<char,int>::iterator it=data.begin();it!=data.end();++it)
      fila.push(mp(-(it->second),it->first));

    int maior=fila.top().f;

    while(fila.top().f==maior && !fila.empty())
    {
      k+=fila.top().s;
      fila.pop();
    }
    
    cout<<k;
    cout<<"\n";
  }
  
  return 0;
}