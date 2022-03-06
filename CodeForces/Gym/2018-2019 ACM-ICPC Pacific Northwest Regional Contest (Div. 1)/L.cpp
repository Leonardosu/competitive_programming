/*
Problem: L - Liars
Link: https://codeforces.com/gym/101982/problem/L
Complexity: O(N)
Solution: Prefix sum
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
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'
 
using namespace std;
 
int events[MAXN];
 
int main(int argc, char** argv)
{
	optimize;
 
    int N, l, r;
 
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;
 
        events[l]++;
        events[r + 1]--;
    }
 
    int ans = -1, sum = 0;
 
    for (int i = 0; i <= N; i++)
    {
        sum += events[i];
 
        if (sum == i) ans = i;
    }
 
    cout << ans << endl;
 
	return 0;
}