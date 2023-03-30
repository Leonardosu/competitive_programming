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


const int inf = 2e8;
struct BIT {
    using T = int;
    vector<T> bit;
    int N;
    BIT(int n) {
        N = n + 2;
        bit.resize(n + 2, inf);            
    }
    
    void updateL(int x, T val = 1) {
        while(x > 0)
            bit[x] = min(bit[x], val), x -= x&(-x);
    }  

    void updateR(int x, T val = 1) {
        while(x < N)
            bit[x] = min(bit[x], val), x += x&(-x);
    }    

    int queryL(int x) {
        T res = inf;
        while(x > 0)
            res = min(res,bit[x]), x -= x&(-x);
        return res;
    }
    int queryR(int x) {
        T res = inf;
        while(x < N)
            res = min(res,bit[x]), x += x&(-x);
        return res;
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    const int inf = 2e8;
    vector<int> v(n), ans(n, inf);
    for(int &x : v)
        cin>>x;

    BIT b1(n), b2(n);
    for(int i=0;i<n;++i) {
        int curr = min((i + v[i]) + b1.queryL(v[i]), 
                       (i - v[i]) + b2.queryR(v[i]));

        ans[i] = min(ans[i], curr);
        b1.updateR(v[i], -(i+v[i]));
        b2.updateL(v[i], -(i-v[i]));
    }

    b1 = BIT(n), b2 = BIT(n);
    for(int i=n-1;i>=0;--i) {
        int curr = min((-i + v[i]) + b1.queryL(v[i]), 
                       (-i - v[i]) + b2.queryR(v[i]));

        ans[i] = min(ans[i], curr);
        b1.updateR(v[i], -(-i+v[i]));
        b2.updateL(v[i], -(-i-v[i]));
    }

    for(int i=0;i<n;++i)
        cout<<ans[i]<<" ";    
}