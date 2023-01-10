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

const int MAXN = 2e5 + 7;
const int INF = 2e9;
struct node {
	ll sum, mn, mx;

	node(ll sum_ = 0, ll mn_ = INF, ll mx_ = -INF) {
		sum = sum_;
		mn = mn_;
		mx = mx_;
	}

	void merge(node &left, node &right) {
		mn = min(left.mn, right.mn);
		mx = max(left.mx, right.mx);
		sum = left.sum + right.sum;
	}
};


node seg[4*MAXN];
ll lazy[4*MAXN], v[MAXN];

void build(int no, int ini, int fim) {
    if (ini == fim) {
    	seg[no] = node(v[ini], v[ini], v[ini]);
    	lazy[no] = 0;
    } else {
    	int mid = (ini + fim)/2;
    	int e = 2*no, d = e + 1;
        build(e, ini, mid);
        build(d, mid+1, fim);
        
        seg[no].merge(seg[e], seg[d]);
    }
}

void push(int no, int ini, int fim) {
	if (lazy[no] != 0) {
		int mid = (ini + fim)/2;
		int e = 2*no, d = e + 1;

		seg[e].sum = 1LL * lazy[no] * (mid - ini + 1);
		seg[d].sum = 1LL * lazy[no] * (fim - mid);

		seg[e].mx = seg[d].mx = lazy[no];
		seg[e].mn = seg[d].mn = lazy[no];

		lazy[e] = lazy[d] = lazy[no];
		lazy[no] = 0;
	}
}

void update(int no, int ini, int fim, int l, int r, ll val)
{
	if(l > r) return;
	if(seg[no].mn >= val) return;

	if(l<=ini && fim<=r && seg[no].mx < val) {
		seg[no].sum = val*(fim - ini + 1);
		lazy[no] = seg[no].mx = seg[no].mn = val;
		return;
	}

	push(no, ini, fim);

	int mid = (ini + fim)/2;
	int e = 2*no, d = e + 1;
	if(l <= mid)
		update(e, ini, mid, l, r, val);
	if(r > mid)
		update(d, mid+1, fim, l, r, val);

	seg[no].merge(seg[e], seg[d]);
}

ll money;
int query(int no, int ini, int fim, int l, int r)
{
	if(seg[no].mn > money) return 0;
	if(l<=ini && fim<=r && seg[no].sum <= money)
	{
		money -= seg[no].sum;
		return (fim - ini +1);
	}

	push(no,ini, fim);
	int mid=(ini + fim)/2;
	int e = 2*no, d = e + 1;
	ll ans = 0;

	if(l <= mid)
		ans += query(e, ini, mid, l, r);
	if(r > mid)
		ans += query(d, mid+1, fim, l, r);

	seg[no].merge(seg[e], seg[d]);
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    	cin>>v[i];
    build(1, 1, n);

    while(q--) {
    	ll t, x, y;
    	cin>>t>>x>>y;
    	if(t == 1) {
    		update(1, 1, n, 1, x, y);
    	} else {
    		money = y;
    		cout<<query(1, 1, n, x, n)<<"\n";
    	}
    }
}