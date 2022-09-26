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

const int N = 1e5 + 7;
int dp[N][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin>>s;
	// ll moves = 0;
	
	// 	9 moves
	// 	xxx9xx
	// 	melhor fazer:
	// 	2 moves
	// 	xx10xxx 
	// 	xx01xxx

	

	// // for(char &c : s) {
	// // 	moves += c-'0';
	// // }
	int n = s.size();
	/*
		dp[i][0] = soma 1 em [i-1] e subtrai [10 - x] em (i)
		dp[i][0] = min { dp[i-1][0] - 1(pq n vou precisar adicionar 1 em (i-1))
				   	   { dp[i-1][1] + 1(pq vou precisar adicionar 1)


		dp[i][1] = min { dp[i-1][0], deixa quieto
					   { dp[i-1][1], deixa quieto
	*/
	dp[0][1] = s[0] - '0';
	dp[0][0] = 11 - dp[0][1];

	for(int i=1;i<n;++i) {
		int dig = s[i] - '0';
		dp[i][0] = min(dp[i-1][0]-1, dp[i-1][1]+1) + 10 - dig;
		dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + dig;
	}

	cout<<min(dp[n-1][0],dp[n-1][1])<<"\n";
}