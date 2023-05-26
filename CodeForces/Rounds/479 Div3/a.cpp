#include <bits/stdc++.h>
using namespace std;
 
int n,k;
 
int main()
{
  ios_base::sync_with_stdio(false);	cin.tie(0);
 
  cin>>n>>k;
  for(int i=0;i<k;++i)
  {
  	if(n%10 == 0) n/=10;
  	else n--;
  }
 
  cout<<n<<"\n";
  
}