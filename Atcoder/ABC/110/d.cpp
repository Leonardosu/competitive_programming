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
mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

const ll N = 2e5 + 1, mod = 1e9 + 7;
ll fn[N], fd[N], iv[N];

void initnck() {
    iv[1] = fn[1] = fd[1] = fn[0] = fd[0] = 1;
    for (ll i = 2; i < N; i++){
        iv[i] = (mod - (mod / i) * iv[mod % i] % mod) % mod;
        fn[i] = fn[i - 1] * i % mod;
        fd[i] = fd[i - 1] * iv[i] % mod;
    }
}

ll nck(ll n, ll k) {
    return fn[n] * fd[n - k] % mod * fd[k] % mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    initnck();

    ll n, k;
    cin>>n>>k;

    vi freq;
    for(ll i=2;i*i<=k;++i) {
        if(k%i==0) {
            int cnt=0;
            while(k%i==0)
                k/=i,cnt++;
            freq.pb({cnt});            
        }
    }
    
    if(k>1)
        freq.pb(1);

    //a_1+a_2+...+a_n=freq
    ll ans = 1;
    for(auto sum: freq) {
        // cout<<nck(sum+n-1,sum)<<endl;
        ans = (ans * nck(sum+n-1, sum))%mod;
    }

    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}