#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 302;
ll table[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);


    int n;
    cin>>n;

    for(int i=1;i<=n;++i) 
    	for(int j=1;j<=n;++j) {
    		cin>>table[i][j];
    	}

    ll ans = 0;    	
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j) {
			ll best = INT_MAX;
    		for(int k=1;k<=n;++k) {
    			if(k == i || k == j || i == j) continue;   
    			ll now = table[i][k] + table[k][j];
	    		if(now < table[i][j]) {
	    			cout<<"-1\n";
	    			return 0;
	    		}

				best = min(best, now);
    		}
			if(table[i][j] < best)
				ans += table[i][j];
    	}

    cout<<ans<<endl;
}