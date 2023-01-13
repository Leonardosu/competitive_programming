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
    while(!s.empty() && s.back() == '0')
    	s.pop_back();

    bool flag = false;
    if(s.empty()) flag = true;
    else {
    	flag = true;
    	for(int i=0, j = s.size() - 1; i<j;++i, --j) {
    		if(s[i] != s[j]) {
    			flag = false;
    			break;
    		}
    	}
    }

    cout<<(flag ? "YES" : "NO")<<"\n";
}