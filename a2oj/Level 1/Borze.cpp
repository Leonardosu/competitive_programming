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

    string s, ans;
    cin>>s;

    int n = s.size();
    for(int i=0;i<n;++i) {
    	
    	if(s[i] == '.')
    		ans += '0', i--;
    	else if(s[i+1] == '.')
    		ans += '1';
    	else
    		ans += '2';
    	i++;
    }

    cout<<ans<<"\n";
}