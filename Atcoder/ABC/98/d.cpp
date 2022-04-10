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

	int n;
	cin>>n;
	
	vector<ll> v(n),sum(n+1),xo(n+1);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
		xo[i+1] = sum[i+1] = v[i];
	}
		
	for(int i=0;i<n;++i)
		sum[i+1] += sum[i],  xo[i+1] ^= xo[i];

	ll qnt = 0,curr = 0;

	for(ll i=0;i<n;++i)
	{
		curr = max(curr,i);
		while(curr < n)
		{
			if( (sum[curr+1] - sum[i]) == (xo[curr+1]^xo[i]))
				curr++;
			else
				break;
		}
		
		qnt += curr - i;
	}
	cout<<qnt<<"\n";
}