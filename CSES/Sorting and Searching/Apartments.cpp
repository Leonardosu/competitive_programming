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

    int n, m, k;
    cin>>n>>m>>k;
    vi a(n), b(m);
    for(auto &x : a)
    	cin>>x;
    for(auto &x : b)
    	cin>>x;

    sort(ALL(a));
    sort(ALL(b));

    int ans = 0;
    int id = 0;
    for(int i=0;i<n;++i) {
    	int x = a[i];

    	while(id < m && b[id] < x - k)
    		id++;

    	if(id < m && x - k <= b[id] && b[id] <= x + k)
    		ans++, id++;
    }
    cout<<ans<<'\n';
}