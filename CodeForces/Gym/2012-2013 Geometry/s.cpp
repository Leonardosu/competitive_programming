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

const ld EPS = 1e-6;

struct pt {
	ll x, y;
	pt(ll x=0, ll y=0): x(x), y(y) {}
	pt operator +(pt p) { return pt(x+p.x, y+p.y); }
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    ll norm() {return sqrt(x*x + y*y);}
    void read() {cin>>x>>y;}
};

int signal(ll val) {
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("position.in", "r", stdin);
    freopen("position.out", "w", stdout);
#endif
    pt a, b;
    a.read(); b.read();

    ll A, B, C;
    cin>>A>>B>>C;

    ll signal1 = signal(A * a.x + B * a.y + C);
    ll signal2 = signal(A * b.x + B * b.y + C);

    cout<<((signal1 * signal2 > 0)  ? "YES" : "NO")<<"\n";
}