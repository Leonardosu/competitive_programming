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
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	array<ll,3> v;
	cin>>v[0]>>v[1]>>v[2];
	sort(ALL(v));
	
	if(v[2] > 2*(v[0]+v[1])) cout<<v[0] + v[1];
	else cout<<(v[0]+v[1]+v[2])/3LL<<"\n";
}