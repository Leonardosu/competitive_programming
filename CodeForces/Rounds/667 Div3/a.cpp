#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--) {
		ll a,b;
		cin>>a>>b;
		ll ans = abs(a-b);

		if(ans%10 != 0) ans+=9;
		ans/=10;
		
		cout<<ans<<"\n";
	}
	
}
