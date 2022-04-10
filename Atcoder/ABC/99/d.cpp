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

	int n,c;
	cin>>n>>c;

	int color[n+1][n+1];
	int dist[c+1][c+1];

	
	for(int i=1;i<=c;++i)
		for(int j=1;j<=c;++j)
			cin>>dist[i][j];

	// for(int k=1;k<=c;++k)
	// 	for(int i=1;i<=c;++i)
	// 		for(int j=1;j<=c;++j)
	// 			dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);

	//change[restoDivisao][talCor]
	int change[4][c];
	for(int i=0;i<4;++i)
		for(int j=1;j<=c;++j)
			change[i][j] = 0;
	// memset(change,0,sizeof(change));

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int resto = (i+j)%3,cor;
			cin>>cor;
			for(int k=1;k<=c;++k)
				change[resto][k] += dist[cor][k];
		}


	int ans = INT_MAX;
	for(int i=1;i<=c;++i)
		for(int j=1;j<=c;++j)
			for(int k=1;k<=c;++k)
				if(i != j && i != k && j != k)
				{
					int sum = change[0][i] + change[1][j] + change[2][k];
					if(sum < ans)
						{
							// cout<<i<<","<<j<<","<<k<<" =>"<<sum<<"\n";
							// cout<<change[0][i]<<","<<change[1][j]<<","<<change[2][k]<<" =>"<<sum<<"#\n";

							ans = sum;
						}
				}

	cout<<ans<<"\n";
}