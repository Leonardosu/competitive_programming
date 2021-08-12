#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

    	
const long long int maxn = 1e18 + 100;
struct node
{
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

        if(a == b)
        {
        	v = max(v,val);
        	// v += val;
            return;
        }

        ll mid = (a+b)/2LL;

        if(p <= mid)
        {
            if(l == NULL) l = new node(a, mid,0);

            l->upd(p,val);
        }
        else
        {
            if(r == NULL) r = new node(mid + 1, b,0);

            r->upd(p,val);
        }

        v = max(( (l == NULL)? 0 : l->v ) , ( (r == NULL) ? 0 : r-> v ));
    }

 	ll query(ll i, ll j)
    {
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

	vi v(n);
	vector<ll> d(n),t(n);

	for(int i=0;i<n;++i)	
		cin>>d[i]>>v[i]>>t[i];		
	
	ll best = 0;

	for(int i=0;i<n;++i)
	{
		ll value = 1LL*v[i] + tree->query(d[i] - t[i],d[i]);
		tree->upd(d[i],value);
		best = max(best,value);
	}

	cout<<best<<"\n";
}