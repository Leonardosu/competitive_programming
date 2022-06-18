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
	int n;
	string s;
	cin>>n>>s;

	ll ans = 0;
	vector<pair<char,ll>> stk;
	stk.pb({'!', 0});

	for(int i=0;i<n;++i) {
		ll qnt = stk.back().second;

		if(s[i] != stk.back().first)
		{
			ans += qnt + 1LL;
			stk.pop_back();
			if(stk.back().f == s[i]){
				stk.pop_back();
				stk.pb({s[i], 2LL*qnt + 1LL});
			}
			else 
				stk.pb({s[i], qnt + 1LL});
		}
		else {
			stk.pop_back();
			stk.pb({s[i], qnt + 1LL});
			ans++;
		}
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