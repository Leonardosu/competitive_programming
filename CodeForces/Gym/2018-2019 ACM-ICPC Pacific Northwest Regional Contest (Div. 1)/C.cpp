/*
Problem: C - Contest Setting
Link: https://codeforces.com/gym/101982/problem/C
Complexity: O(N * K)
Solution: Dynamic programming using binary search
Author: Carlos Eduardo (eduardocesb)
*/
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 998244353
#define PRIME 101 
#define MAXN 1010
#define MAXL 23
#define endl '\n'
 
using namespace std;
 
ll dp[MAXN][MAXN];
int N, K;
vi nums;
 
int nxt (int i)
{
    return POS(nums, nums[i] + 1);
}
 
ll solve(int i, int k)
{
    if (k < 0) return 0;
    if (i >= N) return k == 0 ? 1 : 0; 
    if (~dp[i][k]) return dp[i][k];
 
    return dp[i][k] = (solve(i + 1, k) + solve(nxt(i), k - 1)) % MOD;
}
 
 
int main(int argc, char** argv)
{
	optimize;
 
    cin >> N >> K;
 
    for (int i = 0, x; i < N; i++)
    {
        cin >> x;
 
        nums.PB(x);
    }
 
    sort(ALL(nums));
 
    memset(dp, -1, sizeof dp);
 
    cout << solve(0, K) << endl;
 
	return 0;
}