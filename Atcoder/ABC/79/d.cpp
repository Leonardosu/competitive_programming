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

const int N = 10;
int cost[N][N];

void floyd() {
	for(int k=0;k<N;++k)
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin>>n>>m;

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			cin>>cost[i][j];
	
	floyd();

	ll total = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			int val;
			cin>>val;
			if(val != -1) {
				total += cost[val][1];
			}
		}
	cout<<total<<"\n";
}