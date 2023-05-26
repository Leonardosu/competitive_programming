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
    

    int n, m, x, y;
    cin>>n>>m>>x>>y;
    vi a(n), b(m);
    int left = x, right = y;

    for(int &x : a) {
    	cin>>x;
    	left = max(left, x);
    }

    for(int &x : b) {
    	cin>>x;
    	right = min(right, x);
    }

    cout<<(left+1 <= right ? "No War" : "War")<<endl;

    //--------------------------
    cerr<<"\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}