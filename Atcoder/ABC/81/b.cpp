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


	int limit = INT_MAX;
	int n;
	cin>>n;
	for(int i=0;i<n;++i) {
		int x;
		cin>>x;
		int qnt = 0;

		while(x%2 == 0)
			x>>=1, qnt++;
		limit = min(limit, qnt);
	}

	cout<<limit<<"\n";
}