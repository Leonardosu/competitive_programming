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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    int a = 0, b = 0;

    for(int i=0;i<(int)s.size();++i) {
    	if(i%2 == 0) {    	
    		if(s[i] == '1') //start with 0
    			a++;
    		else
    			b++;
    	} else if(i%2 == 1) {
    		if(s[i] == '0') //start with 0
    			a++;
    		else
    			b++;
    	}
    }

    cout<<min(a,b)<<"\n";
}