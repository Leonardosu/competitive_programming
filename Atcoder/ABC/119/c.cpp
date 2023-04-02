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

int n; 
int v[11];
int x, y, z;
int inf = 1e9;
int solve(int i, int a, int b, int c) {
	if(i == n) {
		int add = min({a,b,c}) > 0 ? 30 : -inf;
		return abs(a - x) + abs(b - y) + abs(c - z) - add;
	} else {
		int x = v[i++];	
		return min({
			solve(i,a,b,c) - 10,
			solve(i,a+x,b,c),
			solve(i,a,b+x,c),
			solve(i,a,b,c+x)
		}) + 10;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>x>>y>>z;
    for(int i=0;i<n;++i)
    	cin>>v[i];
    cout<<solve(0,0,0,0)<<"\n";
}