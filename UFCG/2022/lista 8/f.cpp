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


const long long int maxn = 1e12 + 100;
struct node {
	ll a,b,v;
	node *l,*r;

	node(ll a_ = 0,ll b_ = maxn,ll v_ = 0)
	{
		a = a_, b = b_, v = v_;
		l = r = NULL;
 	}

 	void upd(ll p,ll val)
    {
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

 	ll query(ll i, ll j)
    {
        if(i > b || j < a) return 0LL;

        if(i <= a && b <= j) return v;

        ll A = (l == NULL)? 0 : l->query(i, j);

        ll B = (r == NULL)? 0 : r->query(i, j);

        return max(A, B);
    }
};


node *tree = new node();
const int N = 1e5 + 10;
ll volume[N], dp[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;++i) {
		ll r, h;
		cin>>r>>h;
		volume[i] = r*r*h;
	}
	ll ans = 0;
	for(int i=0;i<n;++i) {
		ll val = tree->query(0, volume[i] - 1);
		dp[i] = val + volume[i];
		ans = max(ans, dp[i]);
		ll pos = tree->query(volume[i], volume[i]);
		if(dp[i] > pos) {
			tree->upd(volume[i], dp[i]);
		}
	}

	cout<<fixed<<setprecision(10);
	cout<<1.0*acos(-1)*ans<<"\n";
}
