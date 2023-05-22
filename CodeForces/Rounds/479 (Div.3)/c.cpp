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
    

    int n, k;
    cin>>n>>k;
    vi v(n);
    for(int &x : v) {
    	cin>>x;
    }

    int limit = 1e9;
    sort(all(v));    
    int current = (k == 0 ? v[0]-1 : v[k-1]);


	int menores = 0;
    for(int i=0;i<n;++i) {
    	if(v[i] <= current)
    		menores++;
    }
    
    if(menores != k || 1 > current || current > limit) {
    	cout<<"-1\n";
    } else{
    	cout<<current<<endl;
    }

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}