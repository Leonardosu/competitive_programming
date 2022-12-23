#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int INF = 1e9 + 7;
typedef pair<int,int> ii;
typedef long long int ll;
inline ll gcd(ll a,ll b){	while(b){	a%=b;	swap(a,b);	}	return a;	}
const int N = 110;
const int M = 1010;

int n,m,a,b;
char mat[N][M];
ll ans = 0;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int t;

	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				cin>>mat[i][j];				
			}
		ans = 0LL;

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<m;++j)
			{
				if(mat[i][j] == '.' && mat[i][j+1] == '.' && b <= 2*a)
					mat[i][j] = mat[i][j+1] = '*',ans += b,j++;

				if(mat[i][j] == '.')
					mat[i][j] = '*',ans += a;
			}
			if(mat[i][m] == '.')
				mat[i][m] = '*',ans+=a;
		}
		cout<<ans<<'\n';
	}

}