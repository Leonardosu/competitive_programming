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
	int x, y;	
};

int main() //Distance from a point to a straight line (Part 2)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("distance2.in", "r", stdin);
    freopen("distance2.out", "w", stdout);
#endif

    pt a,b,c;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;

    int A = c.y - b.y;
    int B = b.x - c.x;
    int C = -A*b.x - B*b.y;

    long double dist = abs(A*a.x + B*a.y + C)/sqrt(A*A + B*B);
	cout<<fixed<<setprecision(10);
	cout<<dist<<"\n";    
}