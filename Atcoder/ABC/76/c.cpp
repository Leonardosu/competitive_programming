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

bool fit(int i, string base, string put) {
	for(int j=0;j<sz(put);++j) {
		if(base[i+j] != '?' && 
			base[i+j] != put[j]) {
			return false;
		} 
	} 
	return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    string a, b;
    cin>>a>>b;

    int id = -1;
    for(int i=0;i<=sz(a)-sz(b);++i) {
    	if(fit(i, a, b)) {
    		id = i;
    	}
    }

    if(id == -1) {
    	cout<<"UNRESTORABLE\n";
    } else {
    	for(int i=0;i<id;++i) {
    		if(a[i] == '?') a[i] = 'a';
    		cout<<a[i];
    	}
    	for(int i=0;i<sz(b);++i)
    		cout<<b[i];
    	for(int i=id+sz(b);i<sz(a);++i) {
    		if(a[i] == '?')
    			a[i] = 'a';
    		cout<<a[i];
    	}
    	cout<<endl;
    }
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}