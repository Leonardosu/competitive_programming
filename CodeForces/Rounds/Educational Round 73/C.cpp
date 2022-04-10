#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long int ll;
 
int t;
ll a,b,c,ans;
bool valid(ll times,ll menor)
{
	ll total = a + b + c;
 
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		ans = min(a,b);
		ans = min((a+b+c)/3,ans);
		cout<<ans<<"\n";
	}
 
}