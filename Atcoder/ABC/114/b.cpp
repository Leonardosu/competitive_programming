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

    string s;
	cin>>s;    
    ll target = 753;
    ll ans = 1e9;

    for(int i=0;i+2<sz(s);++i) {

    	ll num = (s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0');
    	// for(int j=0;j<l;++j) {
    	// 	num *= 10;
    	// 	num += s[j] - '0';
    	// }
    	// for(int j=r+1;j<sz(s);++j) {
    	// 	num *= 10;
    	// 	num += s[j] - '0';
    	// }
    	ans = min(ans, abs(num - target));
    }
    cout<<ans<<"\n";
}