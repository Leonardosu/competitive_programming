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

//    *AGC , *ACG , *GAC , A*GC , AG*C
bool valid(int mask) { //ACGT = 1234
    if(mask % 1000 == 123 || mask % 1000 == 132 || mask % 1000 == 312    // caso simples
        || mask == 1132 || mask == 1232 || mask == 1332 || mask == 1432  // A*GC 
        || mask == 1312 || mask == 1322 || mask == 1332 || mask == 1342) // AG*C
            return false;
    return true;
}

const int N = 100 + 7;
const int limit = 10000;
const int mod = 1e9 + 7;
ll dp[N][limit];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;

    dp[0][0] = 1; //dp[tamanho][ultimas 4 letras]

    const int mod = 1e9 + 7;    //ACGT = 1234
    for(int i=0;i<n;++i) {
        for(int mask=0;mask<limit;++mask) {
            if(dp[i][mask] != 0) {
                for(int letra=1;letra<=4;++letra) {
                    int new_mask = (mask%1000) * 10 + letra;
                    if(valid(new_mask)) {
                        dp[i+1][new_mask] = (dp[i+1][new_mask] + dp[i][mask]) % mod;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0;i<limit;++i) 
        ans += dp[n][i];

    cout<<ans%mod<<"\n";
}