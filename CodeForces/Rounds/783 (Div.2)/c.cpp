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



ll cal(vector<ll> v, int ini, int fim, int k)
{
	if(ini < 0 || ini>=v.size())
		return 0;

	ll total = 0, last = 0;
	for (; ini != fim; ini+=k)
    {
        ll curr =  (last / v[ini]) + 1LL;
        total += curr;
        last = curr * v[ini];
    }
    return total;
}

void solve_task()
{
	int n;

	cin>>n;
	vector<ll> v(n);
	for(ll &x : v)
		cin>>x;

	const ll INF = 1e17;
	ll ans = INF;
	for(int i=0;i<n;++i)
	{
		ll curr = 0;
		if(i)
			curr += cal(v, i-1, -1, -1);
		if(i+1<n)
			curr += cal(v, i+1,n, 1);
		ans = min(ans , curr);
	}
	cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    // cin>>T_T;
    while(T_T--)
        solve_task();
}