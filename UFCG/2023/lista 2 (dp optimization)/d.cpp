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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k, d;
    cin>>n>>k>>d;
    
    vector<ll> v(n+2);
    for(int i=1;i<=n;++i)
        cin>>v[i];


    v[n+1] = 1e16;
    sort(ALL(v));
    vector<ll> prefix(n+2);
    prefix[0]++, prefix[1]--;
    int can = 0;

    for(int i=1;i+k-1<=n;++i) {
        can += prefix[i-1];
        if(can) {
            if(v[i + k - 1] <= v[i] + d) {
                int left = i + k - 1;
                int right = lower_bound(ALL(v), v[i] + d + 1) - v.begin();
                prefix[left] ++;
                prefix[right] --;
            }
        }
    }

    // can = accumulate(ALL(prefix), 0);
    cout<<(prefix.back() ? "YES" : "NO")<<"\n";
}