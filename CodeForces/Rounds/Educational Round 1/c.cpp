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
    
    vector<pair<long double, int>> v(n);
    for(int i=0;i<n;++i)
    {
    	ll x,y;
    	cin>>x>>y;
    	v[i] = {atan2(y, x), i + 1};
    }

    sort(ALL(v));


    const long double PI = acos(-1);
    long double best = 2*PI;
    pii ans;

    for(int i=0;i<n;++i)
    {
    	int j = (i+1)%n;
    	long double dif = v[j].f - v[i].f;

    	if(dif < 0.0)
    		dif += 2.0*PI;

    	if(dif < best)
    	{
    		best = dif;
    		ans = {v[i].s, v[j].s};
    	}
    }
    cout<<ans.f<<" "<<ans.s<<"\n";
}