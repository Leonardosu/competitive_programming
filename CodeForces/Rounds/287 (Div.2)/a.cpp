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

    int n,k;
    cin>>n>>k;
    vector<pii> v(n);

    for(int i=0;i<n;++i)
    {
    	int x;
    	cin>>x;
    	v[i] = {x,i+1};
    }
    sort(ALL(v));

    int ans = 0;
    for(auto &x : v)
    {
    	k-=x.f;
    	if(k>=0)
    		ans++;
    	else
    		break;
    }
    cout<<ans<<"\n";
    for(int i=0;i<ans;++i)
    	cout<<v[i].s<<" ";

}