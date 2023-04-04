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

    int n;
    cin>>n;
    string s = string(n, '0');
    vector<string> ans;

    int last = -1;
    set<string> save;

    for(int i=0;i<(1<<n);++i) {
    	ans.pb(s);
    	save.insert(s);
    	for(int j=0;j<n;++j) {
    		if(j == last) continue;

    		int prev = s[j] - '0';
    		s[j] = (1 - prev) + '0';
    		if(!present(save, s)) {
    			last = j;
    			break;
    		} 
    		s[j] = prev + '0';
    	}	
    }
 
 	for(int i=1;i<sz(ans);++i) {
 		int dif = 0;
 		for(int j=0;j<n;++j)
 			if(ans[i-1][j] != ans[i][j])
 				dif++;

 		assert(dif == 1);
 	}   

 	assert(sz(save) == (1<<n));
    for(auto s : ans)
    	cout<<s<<"\n";
}