/*
Problem: H - Repeating Goldbachs
Link: https://codeforces.com/gym/101982/problem/H
Complexity: O(N * K)
Solution: Brute Force using
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
#define ms 1000010
#define MAXL 23
#define endl '\n'

using namespace std;

bool notPrime[ms];
int primes[ms], qnt;

void sieve(int lim)
{
    for(int i = 2; i < ms; i++)
    {
        if(notPrime[i]) continue;

        primes[qnt++] = i;

        for(int j = i + i; j < ms; j += i)
            notPrime[j] = true;
    }
}

int solve(int x)
{
    if (x < 4) return 0;

    for (int i = 0; i < qnt; i++)
    {
        int p = primes[i];
        int q = x - p;

        if(notPrime[q]) continue;

        if ((q - p) % 2 == 0)
            return 1 + solve(q - p);
    }

    return 0;
}

int main(int argc, char** argv)
{
    optimize;

    sieve(ms - 1);

    int x;

    cin >> x;

    cout << solve(x) << endl;

    return 0;
}