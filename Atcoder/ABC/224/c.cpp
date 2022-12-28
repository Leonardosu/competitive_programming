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

struct point {
    ll x, y;
    point(ll x_, ll y_) : x(x_), y(y_){}

};

bool colinear(point a, point b, point c) {
    ll area = (a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y);
    return area == 0LL;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    vector<point> points;
    cin>>n;
    for(int i=0;i<n;++i) {
        ll x, y;
        cin>>x>>y;
        points.pb(point(x, y));
    }

    ll ans = (n*(n-1LL)*(n-2LL))/6LL;    

    for(int i=0;i<n;++i) {
        map<pair<ll,ll>, int> qnt_angle;
        for(int j=i+1;j<n;++j) {
            if(i != j)  {
                ll dy = points[i].y - points[j].y;
                ll dx = points[i].x - points[j].x;
                ll gg = __gcd(dx, dy);
                dy /= gg;
                dx /= gg;

                ans -= qnt_angle[{dx, dy}];
                qnt_angle[{dx, dy}]++;
            }
        }

    }
    cout<<ans<<"\n";
} 