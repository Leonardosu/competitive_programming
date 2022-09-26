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

const int N = 1007;
int a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;++i) {
    	cin>>a[i]>>b[i];
    }

    int ans = 0;
    for(int i=1;i<=n;++i) {
    	for(int j=1;j<=n;++j) {
    		if(a[i] == b[j] && i != j) {
    			a[i] = -1;
    		}
    	}

    	if(a[i] != -1)
    		ans++;
    }

    cout<<ans<<"\n";
}