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
    int ini = 0;
    int ans = 0;
    set<char> valid;

    for(int i=0;i<s.size();++i) {
    	char c = s[i];
    	if(c != 'A' && c != 'C' && c != 'G' && c != 'T') {
    		ini = i + 1;
    	} else {
    		ans = max(ans, i - ini + 1);
    	}
    }

    cout<<ans<<"\n";
}