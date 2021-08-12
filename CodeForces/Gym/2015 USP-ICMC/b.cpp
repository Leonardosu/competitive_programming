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

	int k,n,m;

	cin>>k;
	vector<string> a(k),b(k);
	for(int i=0;i<k;++i)	
		cin>>a[i]>>b[i];

	int pos = -1;
	int best = -1;
	
	for(int cara=0;cara<k;++cara)
	{
		cin>>n>>m;
		unordered_map<char,int> freq,need;

		for(int i=0;i<n;++i)
		{
			string ss;
			cin>>ss;
			for(int j=0;j<m;++j)
				freq[ss[j]]++;
		}
		
		for(int i=0;i<a[cara].size();++i)
			need[a[cara][i]]++;

		for(int i=0;i<b[cara].size();++i)
			need[b[cara][i]]++;

		int can = INT_MAX; 
		for(auto &[c,qnt] : need)
			can = min(can,freq[c]/qnt);
		
		if(can > best)
			best = can, pos = cara;
	}

	cout<<a[pos]<<" "<<b[pos]<<"\n";
}
