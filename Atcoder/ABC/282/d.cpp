#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int N = 2e5 + 7;
ll color[N];
ll zero = 0, one = 0, ans;
vector<ll> g[N];
vector<ll> a, b;

bool valid = true;

pii dfs(int x, int curr) {
	color[x] = curr;
	pii res = {0,0};

	if(curr == 0) res.f++;
	else res.s++;
	curr = 1 - curr;

	for(ll &y : g[x]) {
		if(color[y] == -1) {
			pii nxt = dfs(y, curr);
			if (nxt.f == -1)
				return nxt;
			res.f += nxt.f;
			res.s += nxt.s;
		} else if(color[y] == color[x])
			return {-1, -1};
	}

	return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin>>n>>m;
    for(int i=0;i<m;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    for(int i=1;i<=n;++i)
    	color[i] = -1;


    ll total = n*(n-1)/2 - m;
    for(int i=1;i<=n;++i) {    	
    	if(color[i] == -1) {
    		pii val = dfs(i, 0);
    		if(val.f == -1) {
    			total = 0;
    			break;
    		}

    		total -= val.f * (val.f - 1LL)/2LL;
    		total -= val.s * (val.s - 1LL)/2LL;
    	}
    }
   
    cout<<total<<"\n";
}