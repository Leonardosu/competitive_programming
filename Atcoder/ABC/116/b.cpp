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
    
    int cur;
    cin>>cur;
    int qnt = 1;
    set<int> vis;

    while(!present(vis, cur)) {
    	vis.insert(cur);
    	qnt++;
    	if(cur%2 == 1) cur = cur*3 + 1;
    	else cur/=2;
    }

    cout<<qnt<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}