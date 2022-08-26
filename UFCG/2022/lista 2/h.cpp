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

const int N = 507;
int n;
int dp[N][N];
string s;

int solve(int l, int r) {
	if(l >= r) return 0;
	int &now = dp[l][r];
	if(now != -1) return now;

	now = r - l;
	for(int i=l;i<r;++i)
		now = min(now, solve(l, i) + solve(i+1, r) + (s[l-1] != s[i]) );
	return now;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>s;
	s = "#" + s;
	memset(dp, -1, sizeof dp);
	cout<<solve(1, n+1)<<"\n";
}