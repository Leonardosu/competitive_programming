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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vi v(n);
    for(int &x : v) {
    	cin>>x;
    }

    vector<vector<pii>> s(*max_element(ALL(v)) * 2 + 1);

    for(int i=0;i<n;++i) {
    	for(int j=0;j<i;++j) {
    		auto &temp = s[v[i] + v[j]];
    		for(auto &[x, y] : temp) {
    			if(x != i && x != j && y != i && y != j) {
    				cout<<"Yes\n";
    				cout<<x+1<<" "<<y+1<<" "<<i+1<<" "<<j+1<<"\n";
    				return 0;
    			}
    		}
    		temp.pb({i, j});
    	}
    }

    cout<<"No\n";
}