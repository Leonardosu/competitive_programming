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

	int n, c;
	cin>>n>>c;
	vector<array<int, 3>> queries(n);
	for(int i=0;i<n;++i) {
		for(int j=0;j<3;++j)
			cin>>queries[i][j];
	}

	const int N = 2e5 + 7;
	int prefix[N], atSameTime[N];
	memset(atSameTime, 0, sizeof atSameTime);

	for(int channel=1;channel<=c;++channel){
		memset(prefix, 0, sizeof prefix);
		for(auto &[l, r, c] : queries)
			if(c == channel) {
				prefix[2*l - 1]++;
				prefix[2*r]--;
			}

		for(int i=1;i<N;++i){
			prefix[i] += prefix[i-1];
			if(prefix[i] > 0)
				atSameTime[i]++;
		}
	}

	int ans = 0;
	for(int i=0;i<N;++i)
		if(atSameTime[i] > ans)
			ans = atSameTime[i];
	cout<<ans<<"\n";
}