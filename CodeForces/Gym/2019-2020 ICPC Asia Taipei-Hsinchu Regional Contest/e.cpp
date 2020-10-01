#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
const int maxn = 1999;
const int inf = 1;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    vector<ll> v;

    while(t--)
    {
        ll k,l;
        cin>>k>>l;
        if(l >= 2000)
        {
            cout<<"-1\n";
            continue;
        }
        
        v.resize(maxn);
        v[0] = -1;
        ll val = (k+1999)/(1998);

        for(int i=1;i<maxn;++i) v[i] = val;
        v[maxn-1] += (k+1999)%(1998);        
        cout<<"1999\n";
        for(int i=0;i<maxn;++i) cout<<v[i]<<" ";

    }    
}