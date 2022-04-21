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
	ll n, m;
	cin>>n>>m;
	vector<ll> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	
	sort(ALL(v));

	ll free = accumulate(ALL(v), 0LL) + n;
	free += v.back();	
	free -= v[0];
	cout<<(free <= m ? "Yes" : "No")<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}