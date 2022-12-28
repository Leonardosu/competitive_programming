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

    int n, m, x;
    cin>>n>>m;
    vi v(n);
	for(int &x : v) 
		cin>>x;
	
	sort(ALL(v));
 
	for(int i=0;i<m;++i) {
		cin>>x;
		int pos = upper_bound(ALL(v),x) - v.begin();
		cout<<pos<<" ";
	}

	cout<<"\n";
}