/*		
	1238 - Combiner
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

string a,b;
int n,x,y;


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  cin>>n;
  for(int T=0;T<n;++T)
  {
    cin>>a>>b;
    x=a.size(); y=b.size();
    
    
    for(int i=0;i<min(x,y);++i)
      cout<<a[i]<<b[i];
    
    if(x>y)
    for(int i=min(x,y);i<max(x,y);++i)
      cout<<a[i];
      
    else
    for(int i=min(x,y);i<max(y,x);++i)
      cout<<b[i];
      
    cout<<"\n";
  }
}