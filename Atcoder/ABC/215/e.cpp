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


const int mod = 998244353;
const int N = 1010;

ll dp[N][15][2050], n;

string s;

void add(ll &x,ll y)
{x = (x+y)%mod;}


ll solve(int pos, int last, int bitmask)
{
	if(pos == n)		
		return (bitmask > 0);
	
	if(dp[pos][last][bitmask] != -1)
		return dp[pos][last][bitmask];

	int type = s[pos] - 'A' + 1;

	
	dp[pos][last][bitmask] = (solve(pos+1,last,bitmask))%mod;

	if(!(bitmask & (1<<type)))	
		dp[pos][last][bitmask] = (dp[pos][last][bitmask] + solve(pos+1,type,bitmask|(1<<type)))%mod;	
	else if(last == type)
		dp[pos][last][bitmask] = (dp[pos][last][bitmask] + solve(pos+1,last,bitmask))%mod;
	
	return dp[pos][last][bitmask];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TT = 1;
	// cin>>TT;
	while(TT--)
	{	
		cin>>n>>s;		
		memset(dp,-1,sizeof(dp));
		cout<<solve(0,0,0)<<"\n";
	}	
}