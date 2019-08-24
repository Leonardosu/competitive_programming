/*						
	2157 - Mirror Sequence
	Leonardo Su 		
	5/19/17, 8:01:38 PM
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

int n,a,b;
string ida,volta;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  string::size_type sz;
  
  
  cin>>n; 
  
  for(int i=0;i<n;++i)
  {
    cin>>a>>b;
    ida.clear(); volta.clear();
    for(int i=a;i<=b;++i)
      ida+=to_string(i);
    
    for(int i=ida.size()-1;i>=0;--i)
      volta+=ida[i];
  
      
    cout<<ida<<volta<<"\n";
  }

}