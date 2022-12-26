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

	int n, m;
	cin>>n>>m;

	ll mat[n][m];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>mat[i][j];

	bool flag = true;
	for(int i1=0;i1<n;++i1) {
		 for(int i2=i1+1;i2<n;++i2) {
		 	for(int j1=0;j1<m;++j1) {
		 		for(int j2=j1+1;j2<m;++j2) {
		 			if (mat[i1][j1] + mat[i2][j2] > mat[i2][j1] + mat[i1][j2]) {
		 				flag = false;
		 				break;
		 			}
		 		}
		 	}
		 }
	}

	cout<<(flag ? "Yes" : "No")<<"\n";
}