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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin>>n>>k;
    int v[n];
    for(int i=0;i<n;++i)
    	cin>>v[i];
    bool wake[n];
    for(int i=0;i<n;++i)
    	cin>>wake[i];

    ll prefix[n], dorm[n];
    prefix[0] = (wake[0] ? v[0] : 0);
    dorm[0] = (!wake[0] ? v[0] : 0);

    for(int i=1;i<n;++i) {
    	prefix[i] = prefix[i-1] + (wake[i] ? v[i] : 0);
    	dorm[i] = dorm[i-1] + (!wake[i] ? v[i] : 0);
    }


    ll ans = 0;
    for(int i=k-1;i<n;++i) {
    	ll curr = prefix[n-1] + dorm[i] - (i>=k ? dorm[i-k] : 0);
    	ans = max(ans, curr);
    }

    cout<<ans<<"\n";
}