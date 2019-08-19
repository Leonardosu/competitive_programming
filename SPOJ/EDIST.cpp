/*
	EDIST SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define N 2010 
using namespace std;
 
int dp[N][N];
int x,y,t;
string a,b;
 
int solve(int n,int m)
{
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
		{
			if(i == 0) dp[i][j] = j;
			else if (j == 0) dp[i][j] = i;
			else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
		}
	return dp[n][m];
}

void clear(int n,int m)
{
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j] = 0;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        clear(a.size(),b.size());
        cout<<solve(a.size(),b.size())<<"\n";
    }
 
    return 0;
} 