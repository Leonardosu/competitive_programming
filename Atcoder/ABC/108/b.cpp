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
    int x,y,a,b;
    cin>>x>>y>>a>>b;

    // int dist = (x-a)*(x-a) + (y-b)*(y-b);
    int dx = a - x, dy = b - y;

    vector<pii> ans(2);

    ans[0] = {a - dy, b + dx};
    ans[1] = {x - dy, y + dx};
    cout<<ans[0].f<<" "<<ans[0].s<<" ";
    cout<<ans[1].f<<" "<<ans[1].s<<"\n";
}