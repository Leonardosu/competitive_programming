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

    int n, q;
    cin>>n>>q;

    string s;
    cin>>s;
    s = '#' + s;

    int count[n+1];
    count[0] = 0;

    for(int i=1;i<=n;++i) {
		count[i] = count[i-1];

    	if(s[i] == 'C' && s[i-1] == 'A')
    		count[i]++;
    }

	while(q--) {
		int l, r;
		cin>>l>>r;
		cout<<count[r] - count[l]<<"\n";
	}
}