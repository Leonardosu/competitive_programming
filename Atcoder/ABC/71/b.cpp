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

bool v[27];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
 
 	string s;
 	cin>>s;
 	for(char &c : s)
 		v[c-'a'] =  true;
 	for(int i=0;i<26;++i) {
 		if(!v[i]) {
 			cout<<char(i+'a')<<endl;
 			return 0;
 		}
 	}

 	cout<<"None\n";
 	
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}