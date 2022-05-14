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

    int n;
    cin>>n;

	vi v(n);    
    for(int i=0;i<n;++i)
    {
    	cin>>v[i];
    }

    sort(ALL(v));
    int prefix[n+1], suffix[n+1];
    prefix[0] = v[0], suffix[n-1] = v[n-1];
    for(int i=1;i<n;++i)
    	prefix[i] = __gcd(v[i], prefix[i-1]);
    for(int i=n-2;i>=0;--i)
    	suffix[i] = __gcd(v[i], suffix[i+1]);

    int best = max(prefix[n-2], suffix[1]);
    for(int i=1;i<n-1;++i)
    	best = max(best, __gcd(prefix[i-1], suffix[i+1]));

    cout<<best<<"\n";
}