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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, target;
    cin>>n>>target;
    map<int, int> pos;
    int a = -1, b = -1;
    for(int i=0;i<n;++i) {
    	int x;
    	cin>>x;

    	if(a != -1) continue;
    	if(pos.count(target-x)) {
    		a = pos[target-x];
    		b = i+1;
    	}
    	pos[x] = i+1;
    }

    if(a == -1) {
    	cout<<"IMPOSSIBLE\n";
    } else {
    	cout<<a<<" "<<b<<"\n";
    }
}