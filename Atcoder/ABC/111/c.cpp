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
mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 100010;
int cnt[2][N];
pii p[2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;++i) {
    	cin>>v[i];
    	int id=i%2;
    	int x=++cnt[id][v[i]];
    	
    	if(p[id].f < x) {
    		p[id].f=x;
    		p[id].s=v[i];
    	}
    }

    sort(cnt[0],cnt[0]+N);
    sort(cnt[1],cnt[1]+N);

    int ans=0;
    if(p[0].s ^ p[1].s) { //diferentes
    	ans=n-p[0].f-p[1].f;
    } else {
    	ans=n-max(p[0].f+cnt[1][N-2], p[1].f+cnt[0][N-2]);
    }
    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}