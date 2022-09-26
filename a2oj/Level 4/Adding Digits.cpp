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

    ll number, div, n;
    cin>>number>>div>>n;

    string ans = "-1";
    for(int i=0;i<10;++i) {
    	if((number*10 + i)%div == 0) {
    		ans = to_string(number) + to_string(i);
    		break;
    	}
    }

    if(ans != "-1") {
    	for(int i=1;i<n;++i)
    		ans += '0';
    }

    cout<<ans<<"\n";
}