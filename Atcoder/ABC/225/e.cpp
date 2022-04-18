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

 
struct pt{
	ll x, y;
	pt(ll a=0, ll b=0){x = a, y = b;}
};

ll cross(pt p1, pt p2){
    return 1ll * p1.y * p2.x - 1ll * p2.y * p1.x;
}


bool cmp(pt &p1, pt &p2){
	pt v = pt(p1.x, p1.y - 1);
	pt u = pt(p2.x, p2.y - 1);
    return cross(u, v) < 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<pt> points;

    for(int i=0;i<n;++i)
    {
    	int x,y;
    	cin>>x>>y;
    	points.pb(pt(x,y));
    }

 	sort(ALL(points), cmp);

 	pt now = pt(0, 1);
 	int qnt = 0;

    for(pt &point : points)
    {
    	pt v = pt(point.x-1, point.y);

        if(cross(v, now) > 0)
        	continue;

        qnt += 1;
        now = pt(point.x, point.y - 1);
    }
 
    cout<<qnt<<"\n";
    return 0;
}