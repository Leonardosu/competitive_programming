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

int n, k;
int solve(int i, int val) {
	if(i == n) return val;


	int x = solve(i+1, val*2);
	int y = solve(i+1, val + k);
	return min(x,y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    

    cin>>n>>k;
    cout<<solve(0, 1)<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}