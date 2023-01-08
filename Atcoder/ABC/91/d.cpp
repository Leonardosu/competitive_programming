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
typedef vector<ll> vi;

inline int count(vector<ll> &v, ll val) {
    return lower_bound(ALL(v), val) - v.begin();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vi A(n), B(n);
    for(ll &x : A) cin>>x;
    for(ll &x : B) cin>>x;

    ll ans = 0;
    int limit = 29;
    vi a(n), b(n);

    for(int bit=0;bit<limit;++bit) {
        ll small = (1 << bit);
        ll big = (1 << (bit + 1));

        for(int i=0;i<n;++i) {
            a[i] = A[i] % big;
            b[i] = B[i] % big;
        }

        sort(ALL(b));
        int qnt = 0;
        for(int i=0;i<n;++i) {
            int x = a[i];
            if (x < small) {
                qnt += count(b, big - x) - count(b, small - x);                
            } else {
                qnt += n - count(b, big + small - x) + count(b, big - x);
            }            
        }
        if(qnt&1)
            ans += small;
    }

    cout<<ans<<"\n";
}