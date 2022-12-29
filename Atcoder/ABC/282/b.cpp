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


bool valid(string a, string b) {
	for(int i=0;i<(int)a.size();++i) 
		if(a[i] == 'x' && b[i] == 'x')
			return false;
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;
    int qnt = 0;
    vector<string> v;
    for(int i=0;i<n;++i) {
    	string s;
    	cin>>s;
    	v.pb(s);
    }

    for(int i=0;i<n;++i)
    	for(int j=i+1;j<n;++j) {
    		if(valid(v[i], v[j])) {
    			qnt++;
    		}
    	}

    cout<<qnt<<"\n";
}