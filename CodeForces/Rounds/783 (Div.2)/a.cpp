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
	ll n,m;
	cin>>n>>m;
	if(n == 1 && m == 1)
		cout<<"0\n";
	else if((n == 1 && m > 2) || (n > 2 && m == 1))
	{
		cout<<"-1\n";
	}
	else
	{
		ll x = min(n-1, m-1);
		ll y = max(n-1, m-1) - x;
		cout<<2LL*x + 2LL*y - (y%2LL)<<"\n";	
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}