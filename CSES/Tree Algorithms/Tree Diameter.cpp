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
int cnt[N];
vector<int> g[N];

void dfs(int x, int p) {
	for(int y : g[x]) {
		if(y != p ){
			cnt[y] = cnt[x] + 1;
			dfs(y, x);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    cnt[1] = 0;
    dfs(1, -1);
    int x = 1;
    for(int i=1;i<=n;++i) {
    	if(cnt[i] > cnt[x])
    		x = i;
    }

    cnt[x] = 0;
    dfs(x, -1);
    cout<<*max_element(cnt+1,cnt+n+1)<<"\n";
}