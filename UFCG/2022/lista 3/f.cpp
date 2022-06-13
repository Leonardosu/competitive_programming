#include "bits/stdc++.h" //Generate a String
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
    ll n, x, y;    
    cin>>n>>x>>y;    
    vector<ll> dp(n+1);
    for(int i=1;i<=n;++i){
    	ll a = dp[i-1] + x, b = dp[i/2] + y;
    	if(i&1)
    		b = dp[(i+1)/2] + y + x;
    	dp[i] = min(a,b);
    }

	cout<<dp[n]<<"\n";	    
}