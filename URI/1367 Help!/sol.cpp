/*	
	1367 - Help!
	Leonardo Su
*/
#include <bits/stdc++.h>
#define N 300

using namespace std;

map<char,int> save;
int n,tempo,x,qnt;
string resp;
char id;
bool vis[800];

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  while(cin>>n && n)
  {
    qnt=tempo=0;
    save.clear();
    memset(vis,false,sizeof vis);
    for(int i=0;i<n;++i)
    {
      
      cin>>id>>x>>resp;
      if(vis[id])
        continue;
      else
      {
        if(resp=="correct")
        {
          vis[id]=true;
          save[id]+=x;
          tempo+=save[id];
          qnt++;
        }
        else
          save[id]+=20;
      }
    }
    cout<<qnt<<" "<<tempo<<"\n";
      
  }
}