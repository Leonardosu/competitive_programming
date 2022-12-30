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

struct pt {
	int x, y;
	double len() {
		return sqrt(x*x + y*y);
	}
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("length.in", "r", stdin);
    freopen("length.out", "w", stdout);
#endif

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    pt p;
    p.x = (c-a);
    p.y = (d-b);
    cout<<fixed<<setprecision(6);
    cout<<p.len()<<"\n";
}