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
    ll v[n];
    for(int i=0;i<n;++i) 
    	cin>>v[i];    
    
    sort(v, v+n);
    ll up = 0;
    ll down = n;    
    for (int i=n-1; i>=0; i--)
        up += 1LL*i*v[i] - 1LL*(n-1-i)*v[i];

    up <<= 1LL;
    for(int i=0;i<n;++i) {
    	up += v[i];
    }

    ll g = gcd(up, down);
    up /= g;
    down /= g;

    cout<<up<<" "<<down<<"\n";    
}