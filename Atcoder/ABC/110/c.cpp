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

const int S = 26;
int cnt[S][S];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
 	
 	string a, b;
 	cin>>a>>b;
 	int n = sz(a);
	for(int i=0;i<n;++i) {
		cnt[a[i]-'a'][b[i]-'a'] = 1;
	} 	

	bool ok = true;
	for(int i=0;i<S;++i) {
		int x = 0, y = 0;
		for(int j=0;j<S;++j) {
			x += cnt[i][j];
			y += cnt[j][i];
		}

		if(x > 1 || y > 1) {
			ok = false;
			break;
		}
	}

 	cout<<(ok ? "Yes" : "No")<<endl;

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}