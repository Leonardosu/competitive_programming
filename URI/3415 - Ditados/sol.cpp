#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 50
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N;
string S, s;

int dp[MAXN][MAXN];

void reset()
{
    memset(dp, -1, sizeof dp);
}

int solve(int i, int j)
{
    if (i == -1) return j + 1;
    if (j == -1) return i + 1;

    if (~dp[i][j]) return dp[i][j];

    if (S[i] == s[j]) return dp[i][j] = solve(i - 1, j - 1);

    return dp[i][j] = 1 + min({solve(i - 1, j), solve(i, j - 1), solve(i - 1, j - 1)});
}

int main(int argc, char** argv)
{
    optimize;

    cin >> N;

    vector<int> pontos(5, 0);

    for (int i = 0; i < N; i++)
    {

        cin >> S;

        vi temp;
        int menor = INF;

        for (int j = 0; j < 5; j++)
        {
            cin >> s;

            reset();

            int qtd = solve(S.size() - 1, s.size() - 1);

            temp.PB(qtd);

            menor = min(menor, qtd);
        }

        vi a;

        for (int j = 0; j < 5; j++)
        {
            if (temp[j] == menor)
            {
                a.PB(j);
            }
        }

        for (auto x : a)
            pontos[x] += (menor == 0 ? 10 : 5);
    }

    int m = -1;
    
    vi ans;
    for (int i = 0; i < 5; i++)
    {
        if (m < pontos[i])
        {
            ans.clear();
            ans.PB(i + 1);
            m = pontos[i];
        }
        else if (m == pontos[i])
            ans.PB(i + 1);
    }


    cout << fixed << setprecision(1) << (m / 10.0) << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << " ";
        cout << (ans[i]);
    }

    cout << endl;


    return 0;
}