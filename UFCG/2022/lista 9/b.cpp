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
struct piece{
	int a, b, h;
	void readInput() {
		cin>>a>>b>>h;
	}
} pieces[N];

bool comp(piece x, piece y) {
	if(x.b == y.b) return x.a > y.a;
	return x.b > y.b;
}

const ll maxn = 1e9 + 10;
struct node
{
	ll a,b,v;
	node *l,*r;

	node(ll a_ = 0,ll b_ = maxn,ll v_ = 0) {
		a = a_, b = b_, v = v_;
		l = r = NULL;
 	}

 	void upd(ll p,ll val) {
        if(p < a || p > b) return;

        if(a == b) {
        	v = val;
            return;
        }

        ll mid = (a+b)/2LL;

        if(p <= mid) {
            if(l == NULL) l = new node(a, mid,0);
            l->upd(p,val);
        } else {
            if(r == NULL) r = new node(mid + 1, b,0);
            r->upd(p,val);
        }

        v = max(( (l == NULL)? 0 : l->v ), ( (r == NULL) ? 0 : r-> v ));
    }

 	ll query(ll i, ll j) {
        if(i > b || j < a) return 0LL;

        if(i <= a && b <= j) return v;

        ll A = (l == NULL)? 0 : l->query(i, j);
        ll B = (r == NULL)? 0 : r->query(i, j);

        return max(A,B);
    }
};


node *tree = new node();

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;++i) {
		pieces[i].readInput();
	}

	sort(pieces, pieces + n, comp);
	ll ans = 0;
	for(int i=0;i<n;++i) {
		ll pos = pieces[i].b;
		ll value = tree->query(0, pos - 1) + pieces[i].h;
		if(tree->query(pieces[i].a, pieces[i].a) < value) {
			tree->upd(pieces[i].a, value);
		}
		ans = max(ans, value);
	}
	cout<<ans<<"\n";
}