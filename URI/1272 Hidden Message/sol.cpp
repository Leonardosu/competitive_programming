/*		
	1272 - Hidden Message
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 120
using namespace std;

string frase,k;
int n;
bool flag=true;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    

  cin>>n;
  getline(cin,frase);

  for(int i=0;i<n;++i)
  {
    getline(cin,frase); k.clear(); flag=true;
    for(int j=0;j<frase.size();++j)
    {
      if(frase[j]!=' ' && flag)
      {
        k+=frase[j];
        flag=false;
      }
      else if(frase[j]==' ')
        flag=true;
    }

    cout<<k<<"\n";
  }
  return 0;
}