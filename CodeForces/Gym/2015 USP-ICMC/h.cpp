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

const int M = 26;
ll custo[M][M];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i=0;i<M;++i)	
		for(int j=0;j<M;++j)
			cin>>custo[i][j];


	// char(i) -> char(k) -> char(j) ??, garantir 
	// cout<<"-----------------\n";
	for(int k=0;k<M;++k)
		for(int i=0;i<M;++i)
			for(int j=0;j<M;++j)	
				custo[i][j] = min(custo[i][j], custo[i][k] + custo[k][j]);
	
	for(int i=0;i<M;++i)
		custo[i][i] = 0;


	ll ans = 0;
	string s;
	cin>>s;
	int i = 0, j = s.size() - 1;

	while(i<j)
	{
		ll best = INT_MAX;
		int a = s[i] - 'a', b = s[j] - 'a';

		for(int letra=0;letra<26;++letra)
		
			best = min(best,custo[a][letra] + custo[b][letra]);
		
		i++,j--;
		ans += best;
	}
	cout<<ans<<"\n";
}
