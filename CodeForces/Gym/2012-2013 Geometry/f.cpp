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

const double EPS = 1e-6;

int main() //Distance from a point to a straight line
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("distance1.in", "r", stdin);
    freopen("distance1.out", "w", stdout);
#endif

    long double a,b,c, x, y;
    cin>>x>>y;
    cin>>a>>b>>c;

    long double dist = abs(a*x + b*y + c) / sqrt(a*a + b*b);

	cout<<fixed<<setprecision(10);
	cout<<dist<<"\n";    
}

