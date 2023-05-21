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

vector<string> QW = {
	"qwertyuiop",
	"asdfghjkl;",
	"zxcvbnm,./"
};

char moved(char c, int k) {
	for(string s : QW) {
		int pos = -1, i = 0;
		for(char q : s) {
			if(q == c) {
				pos = i;
				break;
			}
			i++;
		}

		if(pos != -1) {
			return s[(pos+k)%sz(s)];
		}
	}

	return '?';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    char t;
    cin>>t;
    int k = (t == 'L' ? 1 : -1);

    string s;
    cin>>s;
    for(char &c : s) {
    	c = moved(c, k);
    }
    cout<<s<<endl;

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}