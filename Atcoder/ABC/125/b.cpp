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

    int best = 0;
    int n;
    cin>>n;
    vi v(n), c(n);
    for(int i=0;i<n;++i)
    	cin>>v[i];
    for(int i=0;i<n;++i)
    	cin>>c[i];
    for(int i=0;i<n;++i)
    	best += max(0, v[i] - c[i]);
    cout<<best<<"\n";
}