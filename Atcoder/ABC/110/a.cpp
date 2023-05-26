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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    

    vi v(3);
    for(int &x : v)
    	cin>>x;

    sort(all(v));
    int ans = 0;
    do {

    	int cur = v[0] * 10 + v[1] + v[2];
    	ans = max(ans, cur);
    }while(next_permutation(all(v)));

    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}