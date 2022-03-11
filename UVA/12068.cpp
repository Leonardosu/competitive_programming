#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
void solve_task(int Q)
{
	int n;
	cin>>n;
	vector<ll> v(n);
	ll mult = 1;
	for(ll &x : v)
	{
		cin>>x;
		mult *= x;
	}
	ll up = n * mult,down = 0;
	for(ll &x : v)
		down += mult/x;
	ll div = gcd(up,down);

	cout<<"Case "<<Q<<": "<<up/div<<"/"<<down/div<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	for(int i=1;i<=T_T;++i)
	{
		solve_task(i);
	}
}