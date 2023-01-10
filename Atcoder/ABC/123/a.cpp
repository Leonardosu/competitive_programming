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
	
	int n = 5;
	vi v;
	for(int i=0;i<n;++i) {
		int x;
		cin>>x;
		v.pb(x);
	}
	int k;
	cin>>k;

	bool flag = false;

	for(int i=0;i<n;++i) {
		for(int j=i+1;j<n;++j)
			if(abs(v[i] - v[j]) > k) {
				flag = true;
				break;
			}
	}
	if(!flag) cout<<"Yay!\n";
	else cout<<":(\n";
}