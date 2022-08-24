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

const int N = 107;
const int M = 2e5 + 7;
const int base = 1e5;

int a[N], b[N];
int dp[N][M];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin>>n>>k;
	for (int i = 1; i <= n; ++i) cin>>a[i];
	for (int i = 1; i <= n; ++i) cin>>b[i];
	memset(dp, 0xcf, sizeof dp);

	dp[0][base] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 200000; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j - (a[i] - k * b[i]) < 200000 && j - (a[i] - k * b[i]) > 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - (a[i] - k * b[i])] + a[i]);
		}
	}

	cout<<(dp[n][base] ? dp[n][base] : -1)<<"\n";
}