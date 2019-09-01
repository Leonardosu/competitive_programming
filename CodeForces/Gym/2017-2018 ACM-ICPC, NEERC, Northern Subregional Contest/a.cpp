#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e6 + 100;
long long int precalc[MAXN];
 
void solve() 
{ 
    // 7
    for (int i = 6; i < MAXN; i++) 
        precalc[i] = max(precalc[i], 7LL + precalc[i-3]);    
 
    // 4
    for (int i = 8; i < MAXN; i++) 
        precalc[i] = max(precalc[i], 4LL + precalc[i-4]);

    // 1
    for (int i = 4; i < MAXN; i++) 
        precalc[i] = max(precalc[i], 1LL + precalc[i-2]);
    
 
    #ifdef LOCAL
    for (int i=0; i<=10; i++) 
        fprintf(stderr, "%lld ", precalc[i]);    
    
    fprintf(stderr, "\n");
    #endif
}
 
int main() 
{
    #ifndef LOCAL
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    #endif
 
    precalc[0] = 0;
    precalc[1] = 0;
    precalc[2] = 1;
    precalc[3] = 7;
    precalc[4] = 4;
    precalc[5] = 8;
    precalc[6] = 14;
    precalc[7] = 11;
 
    solve();
 
    int N;
    scanf(" %d", &N);
    printf("%lld\n", precalc[N]);
 
    return 0;
}