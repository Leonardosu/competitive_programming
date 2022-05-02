#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int a = 0, b = 0;
    vi v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }

    sort(ALL(v));
    reverse(ALL(v));
    
    for(int i=0;i<n;++i)
    {
        if(i&1)
            a -= v[i];
        else
            a += v[i];
    }

    cout<<a<<"\n";
}