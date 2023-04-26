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

    int n;
    cin>>n;

    map<int,int> freq;
	for(int i=0;i<n;++i) {
		int x;
		cin>>x;
		freq[x]++;
		freq[x-1]++;
		freq[x+1]++;
	}    

	int best = 0, id = 0;
	for(auto [x, cnt] : freq) {
		if(cnt > best) {
			best = cnt;
			id = x;
		}
	}
	cout<<best<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}