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

const int N = 2e5 + 7;
int dp[N];
string s;

void solve_task()
{
	cin>>s;

	int last[27];
	memset(dp, -1, sizeof dp);
	memset(last, -1, sizeof last);

	for(int i=0;i<s.size();++i)
	{
		int x = s[i] - 'a';		
		int npega = (i ? dp[i-1] + 1: 1);
		int pega = INT_MAX;
		if(last[x] != -1)
		{
			//012
			//aba
			pega = (i - last[x] - 1) + (last[x] == 0 ? 0 : dp[last[x]-1]);
		}

		dp[i] = min(npega, pega);
		last[x] = i;
	}

	cout<<dp[s.size()-1]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}