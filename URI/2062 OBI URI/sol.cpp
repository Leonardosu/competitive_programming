/*						
	2062 - OBI URI
	Leonardo Su 		
*/
#include <bits/stdc++.h>
using namespace std;

int n,cont,tam;
string name;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n;
  tam=n;
  while(tam--)
  {
    cin>>name;
    
    if(name.size()!=3) cout<<name;
    else
    {
      if(name[0]=='O' && name[1]=='B') cout<<"OBI";
      else if(name[0]=='U' && name[1]=='R') cout<<"URI";
      else cout<<name;
    }
    if(tam!=0)cout<<" ";
  }
  cout<<"\n";
  
  
  return 0;
}