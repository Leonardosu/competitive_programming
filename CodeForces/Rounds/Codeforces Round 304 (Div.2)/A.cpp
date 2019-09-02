#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
ll k,w,n;
ll ans = 0;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
 
	cin>>k>>n>>w;
 
	ll custo = 0;
	for(int i = 1;i <= w;++i)
		custo+=k,ans+=custo;
 
	cout<<max(ans-n,(ll)0)<<"\n";
}