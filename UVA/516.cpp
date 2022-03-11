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

inline ll poww(ll a, ll b){ll res = 1LL;while (b > 0LL){if(b & 1) res = (res * a);a = (a * a);b >>= 1;}return res;}

void solve_task(ll number)
{
	vector<pii> ans;

	for(ll i=2;i*i<=number;++i)
	{
		if(number%i == 0)
		{
			int qnt = 0;
			while(number%i == 0)
				number/=i, qnt++;
			ans.pb({i, qnt});
		}
	}
	if(number > 1)
		ans.pb({number, 1});
	int n = ans.size();
	for(int i=n-1;i>=0;--i)
	{
		cout<<ans[i].f<<" "<<ans[i].s;
		if(i != 0)
			cout<<" ";
	}
	cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string line;

	while(getline(cin, line))
	{
		istringstream iss(line);
		ll number = 1, base, power;
		while(iss>>base)
		{
			if(base == 0) break;
			iss>>power;
			number *= poww(base, power);
		}
		if(number == 1) break;
		solve_task(number - 1);
	}
}