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

    ll n, d, x;
    cin>>n>>d>>x;
    ll curr = 0;
    for(int i=0;i<n;++i)
    {
    	ll l;
    	cin>>l;

    	curr += (d-1LL)/l + 1LL;
    	//l +1 + 2L + 1 + 3l + 1
    	// xl + 1 <= d
    	//
    	// curr += d + (d+1LL)*l/2;
    }
    cout<<curr + x<<"\n";
}