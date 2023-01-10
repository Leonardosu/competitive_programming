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
	int n, k;
	cin>>n>>k;
	vi v;

	for(int i=0;i<n*k;++i) {
		int x;
		cin>>x;
		v.pb(x);
	}

	int mid = n - (n+1)/2;
	int i = n*k - 1, j = 0;
	ll ans = 0;

	while(j < k) {
		i -= mid;
		ans += v[i];
		i--;
		j++;
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