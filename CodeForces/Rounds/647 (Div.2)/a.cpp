#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;
typedef pair<int,int> ii;
typedef long long int ll;
inline ll gcd(ll a,ll b){	while(b){	a%=b;	swap(a,b);	}	return a;	}



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int casos;
	cin>>casos;
	while(casos--)
	{
		ll a,b;
		ll x = 0,y = 0;

		cin>>a>>b;

		x = min(a,b);
		y = max(a,b);
		ll ans = 0;

		while(x <= y)
		{
			if( x > y) break;

			if(x<<3 <= y) x = x<<3;
			else if(x<<2 <= y) x = x<<2;
			else if(x<<1 <= y) x = x<<1;
			else break;

			ans++;
			if(x == y) break;
		}


		if(x != y) cout<<"-1\n";

		else
			cout<<ans<<"\n";

	}


}