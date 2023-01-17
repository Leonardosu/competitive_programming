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
    typedef pair<double, double> interval;
    vector<interval> v(n);
    for(auto &i : v) {
    	int t; cin>>t;
    	cin>>i.f>>i.s;
    	if(t == 2)
    		i.s-=0.5;
    	if(t == 3)
    		i.f+=0.5;
    	if(t == 4)
    		i.f+=0.5,i.s-=0.5;
    }

    ll ans = 0;
    sort(ALL(v));
    function<bool(interval, interval)> intersect = [&](interval a, interval b) {
    	return a.s >= b.f;
    };

    for(int i=0;i<n;++i){
    	for(int j=i+1;j<n;++j) {
    		if(intersect(v[i], v[j])) {
    			ans++;
    		}
    	}    	
    }
    cout<<ans<<"\n";
}