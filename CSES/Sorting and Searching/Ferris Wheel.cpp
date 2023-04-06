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
    
    int n, limit;
    cin>>n>>limit;
    vi v(n);
    for(auto &x : v)
    	cin>>x;
    sort(ALL(v));

    int last = n - 1;
    int ans = 0;
    for(int i=0;i<n && i <= last;++i) {
    	ans++;
		if(v[i] + v[last] > limit) {
			i--;
		}
		last--;
    }
    cout<<ans<<"\n";
}