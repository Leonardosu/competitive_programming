#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int maxn = 1;
const int inf = 1;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    bool can = true;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k)
            {
                if(i != j && j != k && i != k)
                {
                    if((v[i]-v[j])%v[k] != 0) can = false;
                }
            }
    }
    if(can) cout<<"yes\n";
    else cout<<"no\n";
}