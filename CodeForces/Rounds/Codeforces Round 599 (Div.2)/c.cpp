#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define vi vector<int> v;
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
const int N = 100000;
const int INF = 1e9;
const int MOD = 1e9 + 7;
ll n;
 
bool prime(ll n)
{
 
	for(ll i = 2; i*i <= n ;++i)
	{
		if(n%i == 0)
			return false;
	}
 
	return true;
}
 
ll divisors(ll n) 
{
	ll qnt = 0;
	ll ans = 0;
	vector<ll> div;
	set<ll> save;
 
	for(ll i = 2; i*i <= n ;++i)
	{
		if(n%i == 0)
		{
			if(prime(i))
			{
				save.insert(i);
				ans = i;
			}
 
			if(n/i != i)
			{
				if(prime(n/i))
					save.insert(n/i);
			}
		}
	}
 
	qnt = save.size();
	if(qnt == 0LL) return n;
	if(qnt == 1LL) return ans;
	if(qnt >= 2LL) return 1;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>n;
 
	ll ans = divisors(n);
 
	cout<<ans<<"\n";
}