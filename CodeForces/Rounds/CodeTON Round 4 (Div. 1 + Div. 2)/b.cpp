#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve_task() {
	ll n;
	cin>>n;
	if(n%2LL == 0) {
		cout<<"-1\n"; 
		return;
	}
	vector<int> ans;
	while(n) {
		n/=2;
		ans.pb((n%2==0 ? 1 : 2));
	}

	reverse(all(ans));
	cout<<sz(ans)<<endl;
	for(int x : ans)
		cout<<x<<" ";
	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}