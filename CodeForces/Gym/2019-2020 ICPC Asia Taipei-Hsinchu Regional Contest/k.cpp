#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
const int maxn = 1010;
const int inf = 1e9;
const int mod = 1e9 + 7;

ll dp[maxn][maxn];
ll esquerda[maxn],direita[maxn];


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll ans = 0LL;
        priority_queue<int, vector<int>, greater<int> >fila;

        for(int i=1;i<=n;++i) 
        {
            int x;
            cin>>x;
            fila.push(x);
        }
        

        while(fila.size() > 1)
        {
            int a = fila.top(); fila.pop();
            int b = fila.top(); fila.pop();
            ans += a + b;
            fila.push(a+b);
        }
        cout<<ans<<"\n";
    }
    
}