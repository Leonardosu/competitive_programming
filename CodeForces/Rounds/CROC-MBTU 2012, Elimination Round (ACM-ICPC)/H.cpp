//Queries for Number of Palindromes
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

int q;
bool palin[maxn][maxn];
ll dp[maxn][maxn];
char s[maxn];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(palin,false,sizeof(palin));

    string x;
    cin>>x;
    cin>>q;

    int n = x.size();
    for(int i=0;i<n;++i) s[i+1] = x[i];

    
    for(int i=1;i<=n;++i) palin[i][i] = true;

    for(int l=2;l<=n;++l)
        for(int i=1;i<=n-l+1;++i)
        {
            int j = i + l - 1;
            if(l == 2) palin[i][j] = (s[i] == s[j]);
            else	palin[i][j] = (s[i] == s[j] && palin[i+1][j-1]);			
        }

    for(int i=1;i<=n;++i) dp[i][i] = 1;

    for(int l=2;l<=n;++l)
        for(int i=1;i<=n-l+1;++i)
        {
            int j = i + l - 1;
            if(palin[i][j]) dp[i][j]++;
            dp[i][j] += dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];			
        }
    
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(b < a) swap(a,b);
        cout<<dp[a][b]<<"\n";
    }
		
}