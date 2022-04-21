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
    vi v(n+2), pre(n+2);

    for(int i=1;i<=n;++i)
    {
    	cin>>v[i];
    	pre[i] = pre[i-1] + abs(v[i] - v[i-1]);
    }

    pre[n+1] = pre[n];

    for(int i=1;i<=n;++i)
    {
    	//skipping 'i'

    	ll cost = pre[n] + abs(v[n]);
    	ll jump = abs(v[i] - v[i-1]) + abs(v[i+1] - v[i]);
    	cout<<cost - jump + abs(v[i-1] - v[i+1])<<"\n";
    }
}