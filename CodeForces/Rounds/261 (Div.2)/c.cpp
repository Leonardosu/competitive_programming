#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
const int maxn = 1010;

ll n,d,k;
int ans[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>k>>d;
	ll prod = 1;
	bool can = false;
	for(int i=1;i<=d;++i) {
		prod*=k;
		if(prod >= n) {
			can = true;
			break;	
		}
	}	

	if(!can) cout<<"-1\n";
	else {	
		for(int i=1;i<n;++i) {
			for(int j=0;j<d;++j) ans[i][j] = ans[i-1][j];
			for(int j=d-1;j>=0;--j) {
				ans[i][j] = (ans[i][j] + 1)%k;
				if(ans[i][j]) break;
			}
		}

		for(int i=0;i<d;++i) {
			for(int j=0;j<n;++j)
				cout<<ans[j][i] + 1<<" ";
			cout<<"\n";
		}
	}
	
}	