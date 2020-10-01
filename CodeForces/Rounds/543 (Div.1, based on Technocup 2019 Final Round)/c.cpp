#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 5010;

int lcs[maxn][maxn];
int dp[maxn];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,a,b;
    string s;
    
    cin>>n>>a>>b;
    cin>>s;
    s = " " + s;

    for(int i=1;i<=n;++i) 
        for(int j=1;j<=n;++j)   //dp[i][j] = k , s[i-k] = s[j-k],...,s[i] = s[j]
        {
            if(s[i] == s[j])
                lcs[i][j] = lcs[i-1][j-1] + 1;
        } 
	
    dp[0] = 0LL;
    for(int i=1;i<=n;++i)
    {
        dp[i] = dp[i-1] + a;
        for(int j=1;j<i;++j)
        {
            int l = min(i - j , lcs[i][j] ); //tamanho da substring
            dp[i] = min(dp[i],dp[i-l] + b);
        }
    }
    cout<<dp[n]<<"\n";
}