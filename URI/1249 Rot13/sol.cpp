/*	
	1249 - Rot13
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

string frase;


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  while(getline(cin,frase))
  {
    for(int i=0;i<frase.size();++i)
    {
      if(isalpha(frase[i]))
      {
        if(frase[i]>='a' && frase[i]<='z')
        {
          if(frase[i]+13>'z')
            cout<<(char)(frase[i]-13);
          else
            cout<<(char)(frase[i]+13);
        }
          
        if(frase[i]>='A' && frase[i]<='Z')
        {
          if(frase[i]+13>'Z')
            cout<<(char)(frase[i]-13);
          else
            cout<<(char)(frase[i]+13);
        }
        
      }
      else
        cout<<frase[i];
    }
    cout<<"\n";
  }
  
}

