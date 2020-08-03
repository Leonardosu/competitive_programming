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
	int t;

	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int ans = 0;
		if(b > a) swap(a,b);
		ans = (a/2)*b;

		a = a%2;
		ans += a*((b+1)/2);
		cout<<ans<<"\n";
	}

}