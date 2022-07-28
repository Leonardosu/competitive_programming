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

const int N = 1e5 + 7;
int n, v[N], vis[N];
int qtd[N], a[N];

void solve(int i) {
	queue<pii> q;
	q.push({v[i], 0});

	while(!q.empty()) {
		auto [x, w] = q.front(); q.pop();

		if(x >= N || vis[x] == i) continue;

		vis[x] = i;
		qtd[x] ++;
		a[x] += w;

		w++;
		q.push({x<<1, w});
		q.push({x>>1, w});
	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;++i) {
    	cin>>v[i];
    	solve(i);
    }

    int ans = 1e9;
    for(int i=0;i<N;++i)
    	if(qtd[i] == n)
    		ans = min(ans, a[i]);

    cout<<ans<<"\n";
}