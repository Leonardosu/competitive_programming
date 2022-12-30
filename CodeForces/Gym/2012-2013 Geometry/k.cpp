#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
#define EPS 1e-6
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef ONLINE_JUDGE
    freopen("intersec1.in", "r", stdin);
    freopen("intersec1.out", "w", stdout);
#endif

    array<ld, 3> l1, l2;
    for(int i=0;i<3;++i)
        cin>>l1[i];
    
    for(int i=0;i<3;++i)
        cin>>l2[i];

    //a.x + b.y + c = 0
    int a = 0, b = 1, c = 2;
    ld bottom = (l1[b]*l2[a] - l1[a] * l2[b]);
    
    ld x = (l2[b]*l1[c] - l2[c]*l1[b]) / bottom;
    ld y = (l1[a]*l2[c] - l1[c]*l2[a]) / bottom;

    cout<<fixed<<setprecision(12);
    cout<<x<<" "<<y<<"\n";
}