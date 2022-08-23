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

const int N = 2e5 + 7;
int beauty[N], ans[N];
vector<int> divisores[N], g[N];
int qnt[N];

void dfs(int x, int pai, int lv, int value) {
	ans[x] = value;

	for(int &div : divisores[x]) {
		if(lv - 1 <= qnt[div]) {
			ans[x] = max(ans[x], div);		
		}
		qnt[div]++;
	}

	int newValue = __gcd(value, beauty[x]);
	lv++;
	for(auto &y : g[x]) {
		if(y != pai) {
			dfs(y, x, lv, newValue);
		}
	}

	for(int &div : divisores[x])
		qnt[div]--;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>beauty[i];
		int x = beauty[i];
		for(int j=1;j*j<=x;++j) {
			if(x % j == 0) {
				divisores[i].pb(j);
				if(x/j != j)
					divisores[i].pb(x/j);
			}
		}
	}

	for(int i=1;i<n;++i) {
		int x, y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}

	dfs(1, -1, 0, beauty[1]);
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
}