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
vector<int> g[N];
int sz[N];
int n;

int get_subtree_sz(int x, int p = -1) {
	sz[x] = 1;
	for(int &y : g[x]) {
		if(y != p) {
			sz[x] += get_subtree_sz(y, x);
		}
	}
	return sz[x];
}

int get_centroid(int x, int p = -1) {
	for(int &y : g[x]) {
		if(y != p && sz[y] * 2 > n) {
			return get_centroid(y, x);
		}
	}
	return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<n;++i) {
    	int a, b;
    	cin>>a>>b;
    	g[a].pb(b);
    	g[b].pb(a);
    }

    get_subtree_sz(1);
    cout<<get_centroid(1)<<"\n";
}