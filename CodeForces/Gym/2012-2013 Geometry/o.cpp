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
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef ONLINE_JUDGE
    freopen("line3.in", "r", stdin);
    freopen("line3.out", "w", stdout);
#endif

    ld a,b,c,dist;
    cin>>a>>b>>c>>dist;
    ld delta = dist * sqrt(a*a + b*b);

    cout<<fixed<<setprecision(12);
    cout<<a<<" "<<b<<" "<<(delta - c)<<"\n";
    cout<<a<<" "<<b<<" "<<(delta + c)<<"\n";
    cout<<(1.0*delta)/sqrt(a*a + b*b);
}