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

    set<int> freq;
    int n;
    cin>>n;
    vi v(n);
    bool impar = false;
    int g = -1;
    for(auto &x : v) {

    	cin>>x;
    	if(g == -1)
    		g = x;
    	else
    		g = gcd(g, x);
    }

    cout<<g<<"\n";
}