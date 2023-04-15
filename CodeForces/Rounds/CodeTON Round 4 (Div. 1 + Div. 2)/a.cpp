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
	int n;
	cin>>n;
	vi v(n+1);
	bool valid = false;
	for(int i=1;i<=n;++i) {
		cin>>v[i];
		if(v[i] <= i) valid = true;
	}

	cout<<(valid ? "YES" : "NO")<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}