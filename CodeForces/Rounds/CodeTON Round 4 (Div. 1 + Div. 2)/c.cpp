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
	ll add, remove;
	cin>>n>>remove>>add;

	set<int> unicos;
	vi v;
	ll fixo = 0;
	for(int i=0;i<n;++i) {
		int x;
		cin>>x;
		if(present(unicos, x)) {
			fixo += remove;
		} else {
			unicos.insert(x);
			v.pb(x);
		}
	}

	//remove tudo e coloca o 1
	ll best = remove * sz(v) + add;
	int left = 0;
	int m = sz(v);

	for(auto x : unicos) {
			//montar permutacao ate o valor x
			ll custo = (m - left - 1) * remove + (x - left - 1) * add;
			best = min(custo, best);

		left++;
		//coloco tudo 
	}
	cout<<fixo + best<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}