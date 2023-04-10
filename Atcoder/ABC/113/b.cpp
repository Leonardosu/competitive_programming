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
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    ll t, a;
    cin>>n>>t>>a;

    int id = 1;
    double ans = 1e9;

    for(int i=1;i<=n;++i) {
    	double x;
    	cin>>x;
    	double now = t - x * 0.006;
    	if(abs(now - a) < ans) {
    		ans = abs(now - a);
    		id = i ;
    	}
    }
    cout<<id<<"\n";
}