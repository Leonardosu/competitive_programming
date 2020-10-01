#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
const int maxn = 507;
using namespace std;

bitset<maxn> v[20];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {        
        int n,m;
        cin>>n>>m;
        string s;
        for(int i=0;i<m;++i)
        {
            cin>>s;
            v[i].reset();
            for(int j=0;j<n;++j)
                if(s[j] == '1')
                    v[i].set(j);            
        }

        int op = (1LL << m),ans = 30;
        for(int i=1;i<=op;++i)
        {
            bitset<maxn> atual;
            int cnt = 0;
            for(int j=0;j<m;++j)
            {
                if(i & (1LL << j))
                    atual |= v[j],cnt++;
            }

            if(int(atual.count()) == n) 
                ans = min(cnt,ans);
        }

        if(ans == 30) ans = -1;
        cout<<ans<<"\n";
    }

    return 0;
}