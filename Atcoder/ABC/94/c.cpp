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
	vi v(n),ans(n);
	map<int,int> median;
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
		ans[i] = v[i];
	}
	
	sort(ALL(v));
	int mid = (n)/2;

	for(int i=0;i<n;++i)
	{
		int x = v[i];
		if(median.count(x)) continue;

		if(i < mid)
			median[x] = v[mid];
		else
			median[x] = v[mid-1];
	}
	for(int &x : ans)
		cout<<median[x]<<"\n";
}