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

    int n, ans = INT_MAX;
    cin>>n;
	n*=2;

	int v[n+1];
	for(int i=1;i<=n;++i)
		cin>>v[i];
 
	sort(v+1,v+n+1);
 
 
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			int sum  = 0;
			vector<int> val;
 
			for(int k=1;k<=n;++k) {
				if(k == i || k == j)
					continue;
				val.pb(v[k]);
			}
 
			for(int k=0;k<(int)val.size()-1;k+=2)
				sum+=val[k+1] - val[k];
			ans = min(ans,sum);
		}
	}
 
	cout<<ans<<"\n";
}