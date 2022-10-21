//n*(3*n + 1)/2.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000100
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


ll calc(ll n)
{
    return 1LL * n*(3LL*n + 1)/2;
}


ll solve(ll x)
{
    ll l = 0, r = INF, m, ans = INF;

    while(l <= r)
    {
        m = (l + r) / 2;

        ll aa = calc(m);

        if (aa >= x)
        {
            r = m - 1;
            ans = m;
        }
        else l = m + 1;
    }

    return ans;
}

int main(int argc, char** argv)
{
    optimize;

    int N;

    cin >> N;

    while (N--)
    {
        ll x;

        cin >> x;

        cout << solve(x + 1) - 1 << endl;
    }

    return 0;
}