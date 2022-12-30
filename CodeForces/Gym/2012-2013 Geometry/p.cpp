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
struct pt{
	ld x, y;
	pt(ld x=0, ld y=0): x(x), y(y) {}
};

bool equals(ld x, ld y) {
    return fabs(x-y) < EPS;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef ONLINE_JUDGE
    freopen("point1.in", "r", stdin);
    freopen("point1.out", "w", stdout);
#endif

    pt p;
    ld a, b, c;
    cin>>p.x>>p.y>>a>>b>>c;
    //Ax + By + C = 0
    ld result = a * p.x + b * p.y + c;

    cout<<(equals(result, 0.0) ? "YES" : "NO")<<"\n";
}