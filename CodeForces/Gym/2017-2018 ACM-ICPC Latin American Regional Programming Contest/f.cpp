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

struct segtree {
    using T = long long int;
    struct node {
        T val;
        node(T val=0) : val(val){}
    };

    int n;
    vector<node> tree;
    vector<T> lazy;
    segtree(int n) : n(n), tree(4*n), lazy(4*n) {}

    void push(int no, int l, int r) {
        T &x = lazy[no];
        if(x) {
            tree[no].val = x;
            if(l!=r) lazy[2*no] = x, lazy[2*no+1] = x;
            x = 0;
        }
    }

    void update(int no, int ini, int fim, int l, int r, T val) {
        push(no, ini, fim);
        if(r < ini || fim < l) return;

        if(l<=ini && fim<=r) {
            lazy[no] = val;
            push(no, ini, fim);         
        } else {
            int mid = (ini+fim)>>1;
            int w = no<<1;
            update(w, ini, mid, l, r, val);
            update(w+1, mid+1, fim, l, r, val);

            tree[no].val = max(tree[w].val, tree[w+1].val);
        }
    }

    T query(int no, int ini, int fim, int l, int r) {
        push(no, ini, fim);

        if(r < ini || fim < l) return 0;
        if(l<=ini && fim<=r) return tree[no].val;
        int mid = (ini+fim)>>1;
        return max(query(2*no, ini, mid, l, r),
                query(2*no+1, mid+1, fim, l, r));
    }    

    void update(int l, int r, T val) {update(1, 0, n-1, l, r, val);}
    T query(int l, int r) {return query(1, 0, n-1, l, r);}
};

const int N = 1e5 + 7;
pair<pii, ll> caras[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n;
    cin>>n;
    vi v;

    for(int i=1;i<=n;++i) {
        auto &q = caras[i];
        cin>>q.f.f>>q.f.s>>q.s;
        v.pb(q.f.s);
    }

    sort(caras+1, caras+n+1);
    sort(all(v));

    //merge os caras
    int t = 1, r = 2;
    while(r <= n) {
        if(caras[t].f == caras[r].f) {
            caras[t].s += caras[r].s;
        } else {
            caras[++t] = caras[r];
        }
        r++;
    }
   
    n = t;
    int m = sz(v); //comprime
    for(int i=1;i<=n;++i) {
        caras[i].f.s = lower_bound(all(v), caras[i].f.s) - v.begin() + 1;
    }

    segtree st(m+5);
    ll ans = 0;
    vector<pair<int,ll>> tmp;
    for(int i=n;i>=1;--i) {
        if(caras[i].f.f != caras[i+1].f.f) {
            for(auto [pos, current] : tmp) {
                if(st.query(pos, pos + 1) >= current) continue;
                st.update(pos, pos, current);
            }

            tmp.clear();
        }

        ll value = st.query(caras[i].f.s+1,m+1) + caras[i].s;
        ans = max(ans, value);
        tmp.pb({caras[i].f.s, value});
    }

    cout<<ans<<endl;

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}