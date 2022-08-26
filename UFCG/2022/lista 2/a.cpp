#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;

typedef long long ll;
const int N = 1e3 + 5;
const int inf = 1e5;
int dp[2][N][N] , grid[2][N][N];

void go(char c) {
    cout<<c;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int zi = 0, zj = 0, n;
    bool haveZero = false;
    cin>>n;

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) {
            int x;  
            cin>>x;
            if(x == 0) {
                grid[0][i][j] = grid[1][i][j] = inf;
                haveZero = true;
                zi = i , zj = j;
            }
            else {
                while(x % 2 == 0)   
                    grid[0][i][j]++, x /= 2;
                while(x % 5 == 0)   
                    grid[1][i][j]++, x /= 5;
            }
        }

    for(int i=0;i<n;++i) 
        dp[0][i][n] = dp[0][n][i] = dp[1][i][n] = dp[1][n][i] = 1e9;

    for(int i=n-1;i>=0;--i)
        for(int j=n-1;j>=0;--j)
            dp[0][i][j] = grid[0][i][j] + (i == n-1 && j == n-1 ? 0 : min(dp[0][i+1][j] , dp[0][i][j+1])),
            dp[1][i][j] = grid[1][i][j] + (i == n-1 && j == n-1 ? 0 : min(dp[1][i+1][j] , dp[1][i][j+1]));

    int ans , k;
    if(dp[0][0][0] < dp[1][0][0])   
        ans = dp[0][0][0], k = 0;
    else                            
        ans = dp[1][0][0], k = 1;

    if(haveZero && ans > 0)
    {
        cout<<"1\n";

        int i = 0 , j = 0;
        while(i < zi) go('D') , i++;
        while(j < zj) go('R') , j++;
        while(i < n - 1) go('D') , i++;
        while(j < n - 1) go('R') , j++;
        return 0;
    }

    cout<<ans<<"\n";

    int i = 0 , j = 0;
    while(i != n-1 || j != n-1)
    {
        if(i < n-1 && dp[k][i][j] == grid[k][i][j] + dp[k][i+1][j])
            go('D') , i++;
        else if(j < n-1)
            go('R') , j++;
    }
    cout<<"\n";
    return 0;
}
