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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, sum;
    int a, b;
    cin>>n>>sum;

    vi v, limit;
    int curr = 0;
    for(int i=0;i<n;++i) {
    	cin>>a>>b;
    	curr += a;

    	v.pb(a);
    	limit.pb(b);
    }

    for(int i=0;i<n;++i) {
    	int need = max(0, sum - curr);
    	need = min(need, limit[i] - v[i]);
    	v[i] += need;
    	curr += need;
    }

    if(curr == sum) {
    	cout<<"YES\n";
    	for(int &x : v)
    		cout<<x<<" ";
    	cout<<"\n";
    } else {
    	cout<<"NO\n";
    }
}