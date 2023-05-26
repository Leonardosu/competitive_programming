#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int maxn = 2e5 + 7;
int dp[maxn][4];
int n,k;

vector<int> v,q;

int solve(int i, int j)
{
    if(j <= 0 || i >= n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int melhor = solve(i+1, j);

    int fim = upper_bound(all(v),v[i]+k) - v.begin();

    melhor = max(melhor,fim - i + solve(fim,j-1));

    return dp[i][j] = melhor;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{

		cin>>n>>k;
		v.resize(n);
		q.resize(n);
		memset(dp,-1,sizeof(dp));

		for(int i=0;i<n;++i)
			cin>>v[i];

		for(int i=0;i<n;++i)
			cin>>q[i];

		sort(all(v));

		cout<<solve(0,2)<<"\n";
	}
	
}
