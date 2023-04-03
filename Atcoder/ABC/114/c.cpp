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

const int limit = 1e9;
const int key = (1<<3) - 1;
vector<int> per;
vector<int> k = {3,5,7};

void gen(int num, int digits, int mask) {
	if(digits == 9) {
		return;
	}

	for(int i=0;i<3;++i) {
		num *= 10;
		num += k[i];
		if((mask|(1<<i)) == key) {
			per.pb(num);
		}
		gen(num, digits+1,mask|(1<<i));
		num /= 10;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ans = 0;
    int n;

    cin>>n;
    gen(0,0,0);
    sort(ALL(per));

    for(int x : per) {
    	if(n >= x) {
    		ans++;
    	} else 
    		break;
    }

    cout<<ans<<"\n";
}