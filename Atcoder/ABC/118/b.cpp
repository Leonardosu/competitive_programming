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

    int n, m;
    cin>>n>>m;
    map<int,int> qnt;
    for(int i=0;i<n;++i) {
    	int k;
    	cin>>k;
    	for(int j=0;j<k;++j) {
    		int x;
    		cin>>x;
    		qnt[x]++;
    	}
    }

    int ans = 0;
    for(auto [a, b] : qnt)
    	if(b == n) {
    		ans++;
    	}
    	
    cout<<ans<<"\n";
}