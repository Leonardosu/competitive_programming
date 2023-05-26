#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vi;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	ll ans = 1;

	ll x = 0,y = 0;
	bool many = false;
	for(int i=0;i<n;++i)
	{
		ll a,b;
		cin>>a>>b;
	
		ll plus = min(a,b) - max(x,y);
		if(x != y) plus ++;

		ans += max(plus,0LL);

		x = a;
		y = b;
	}

	cout<<ans<<"\n";
}