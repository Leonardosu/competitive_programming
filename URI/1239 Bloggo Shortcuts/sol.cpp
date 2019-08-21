/*		
	1239 - Bloggo Shortcuts
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 120
#define mp make_pair
using namespace std;

string frase,resp;
int A,B;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    

  while(getline(cin,frase))
  {
    A=B=0; resp.clear();
    for(int i=0;i<frase.size();++i)
    {
      if(frase[i]=='_')
      {
        if(A%2==0)
          resp+="<i>";
        else
          resp+="</i>";
        A++;
      }
      else if(frase[i]=='*')
      {
        if(B%2==0)
          resp+="<b>";
        else
          resp+="</b>";
        B++;
      }
      else
        resp+=frase[i];
    }
    
    cout<<resp<<"\n";
  }


  return 0;
}