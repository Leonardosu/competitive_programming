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

	int n,q;
	cin>>n>>q;
	vi v(n);
	for(int i=0;i<n;++i)	
		cin>>v[i];
	sort(ALL(v));
	cout<<v[q-1]<<"\n";
}
