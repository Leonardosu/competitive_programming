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

    int n;
    cin>>n;
    int v[n+2];

 
    for(int i=1;i<=n;++i){
    	cin>>v[i];
    }

    set<int> free;
    free.insert(-1);
    int ans = 0;
    for(int i=1;i<=n;++i) {
    	int x = v[i];
    	if(!present(free, x-1))
    		ans++;
    	free.insert(x);
    }

    cout<<ans<<"\n";
}