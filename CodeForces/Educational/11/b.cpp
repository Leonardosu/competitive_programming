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

int n, m;
void put(vector<int>&v, int x) {
	if(x <= m)
		v.pb(x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    vector<int> v[4];
	for(int i=0;i<n;++i) {
		v[0].pb(2*i + 1);
		v[1].pb(2*(i+n) + 1);
		v[2].pb(2*(i+n) + 2);
		v[3].pb(2*i + 2);
	}    

	vi ans;
	for(int i=0;i<n;++i) {
		put(ans, v[1][i]);
		put(ans, v[0][i]);
		put(ans, v[2][i]);
		put(ans, v[3][i]);
	}

	for(int &x : ans)
		cout<<x<<" ";
}