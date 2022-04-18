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

void solve_task()
{
	ll n, move, conq;
	cin>>n>>move>>conq;

	vector<int> v(n+1);
	ll total = 0;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		total += v[i];
	}

	ll ans = 0;
	ll capital = 0, resta = n;

	for(int i=1;i<=n;++i)
	{
		//		dist * min(skip or move capital)
		ans += (v[i] - v[capital])*min(resta*conq, move + conq);
		capital = i;	
		resta--;
	}
	cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}