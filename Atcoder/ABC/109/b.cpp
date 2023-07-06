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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n;
    cin>>n;

    string last;
    set<string> asd;

    bool ok = true;
    while(n--) {
    	string curr;
    	cin>>curr;

    	if(present(asd, curr)) {
    		ok = false;
    	}

    	if(!last.empty() && last.back() != curr[0]) {
    		ok = false;
    	}
    	
    	asd.insert(curr);
    	last = curr;
    }

    cout<<(ok ? "Yes" : "No");
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}