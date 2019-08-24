/*	
	1551 - Complete Sentence
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 120
#define mp make_pair
using namespace std;

string frase;
int n;
set<char> palavras;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
    

  cin>>n;
  getline(cin,frase);

  for(int a=0;a<n;++a)
  {
    getline(cin,frase); palavras.clear();
    
    for(int i=0;i<frase.size();++i)
      if(isalpha(frase[i]))
        palavras.insert(frase[i]);

    if(palavras.size()==26)
      cout<<"frase completa\n";

    else if(palavras.size()>=13)
      cout<<"frase quase completa\n";

    else
      cout<<"frase mal elaborada\n";
    
  }
  return 0;
}