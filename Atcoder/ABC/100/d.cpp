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

	int n,m;
	cin>>n>>m;

	vector<array<ll,3>>val(n);

	ll best = 0;
	for(int i=0;i<n;++i)
		for(int k=0;k<3;++k)
			cin>>val[i][k];

	for(int mask=0;mask<8;++mask)
	{
		vector<ll> caras(n);
		for(int i=0;i<n;++i)
		{
			caras[i] = 0;
			for(int k=0;k<3;++k)
			{
				if(mask&(1<<k))
					caras[i] -= val[i][k];
				else
					caras[i] += val[i][k];
			}
		}

		sort(ALL(caras));
		ll curr = 0;
		for(int k=1;k<=m;++k)
			curr += caras[n-k];
		
		best = max(best,curr);
	}
	cout<<best<<"\n";
}