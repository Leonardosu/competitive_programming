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
		ll n;
		cin>>n;
		ll ans = 0LL;

		while(n > 0)
		{
			ans += n;
			n = n>>1;
		}
		cout<<ans<<"\n";
	}


}