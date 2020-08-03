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


ll n,k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int casos;

	cin>>n>>k;
	ll ans = 0LL;
	if(n == k || n == 1)
	{
		cout<<n*3LL<<'\n';
		return 0;
	}

	ll esquerda = k - 1;
	ll direita = n - k;
	ans = n*3LL + min(esquerda,direita);
	cout<<ans<<"\n";

}