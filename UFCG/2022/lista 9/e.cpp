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

const int N = 1e5 + 7;
const int M = sqrt(N);

int last[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	for(int i=1;i<=t;++i) {
		int x, y;
		cin>>x>>y;

		int ans = 0;
		int pos = i - y;
		for(int j=1;j*j<=x;++j) {
			if(x%j == 0) {
				ans += (pos > last[j]);
				last[j] = i;

				if(j != x/j) {
					ans += (pos > last[x/j]);
					last[x/j] = i;
				}
			}
		}

		cout<<ans<<"\n";
	}
}