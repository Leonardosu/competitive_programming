#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,k;
	cin>>n>>k;
	ll qnt = 0;
	if(k == 0)
	{
		cout<<1LL*n*n<<"\n";
		return 0;
	}


	for(int b=1;b<=n;++b)
	{		
		ll p = n/b;
		int r = n%b;

		qnt += p*(max(0, (b-1)	-k +1) );
		qnt += max(0, r-k+1);
	}
	cout<<qnt<<"\n";
}