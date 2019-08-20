/*		
	1120 - Contract Revision
	Leonardo Su
*/
#include <bits/stdc++.h>

using namespace std;

string number,resp;
char x;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  while(cin>>x>>number)
  {
    if ((x=='0' && number[0]=='0') && number.size()==1)
      break;
      
    resp.clear();
    
    for(int i=0;i<number.size();++i)
    {
      if(number[i]!=x)
        resp+=number[i];
    }
  
    bool ok=false;
    bool first=false;
    
    for(int i=0;i<resp.size();++i)
    {
      if(resp[i]!='0' || first )
      {
        cout<<resp[i];
        first=ok=true;
      }
    }
    if(!ok)
      cout<<0;
    cout<<"\n";
  }

  return 0;
}