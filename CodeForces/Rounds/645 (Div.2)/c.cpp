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

ll a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int t;

	cin>>t;
	while(t--)
	{
		ll x,y,xx,yy;
		cin>>x>>y;
		cin>>xx>>yy;

		ll ans = (xx-x)*(yy-y) + 1;
		cout<<ans<<'\n';
	}

}