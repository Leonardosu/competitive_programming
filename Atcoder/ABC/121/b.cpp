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

    int n, m, c;
    cin>>n>>m>>c;
    vi a(m), b(m);

    for(int &x : b)
    	cin>>x;
    int qnt = 0;
    for(int i=0;i<n;++i) {
    	int sum = c;
    	for(int j=0;j<m;++j){
    		int x; cin>>x;
    		sum += x*b[j];
    	}
    	if(sum > 0)
    		qnt ++;
    }
    cout<<qnt<<"\n";
}