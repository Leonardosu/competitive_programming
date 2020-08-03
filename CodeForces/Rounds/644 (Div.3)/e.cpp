#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 55;
typedef pair<int,int> ii;
typedef long long int ll;


int n;
char m[N][N];
bool ok,seen[N][N],can[N][N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	int t;
	cin>>t;
	while(t--)
	{
		memset(can,false,sizeof(can));

		cin>>n;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>m[i][j];

		for(int i=1;i<=n;++i)
		{
			m[0][i] = m[i][0] = '0';
			m[n+1][i] = '0',m[i][n+1] = '0';
		}

		bool flag1 = true;

		for(int i=1;i<n;++i)
		{
			for(int j=1;j<n;++j)
			{
				if(m[i][j] == '1' && (m[i+1][j] == '0' && m[i][j+1] == '0'))
				{
					flag1 = false;
					break;
				}
			}
		}


		if(flag1) cout<<"YES\n";
		else cout<<"NO\n";
	}

}