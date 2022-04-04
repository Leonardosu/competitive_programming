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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("line1.in", "r", stdin);
    freopen("line1.out", "w", stdout);
#endif

    pt c,b;
    cin>>b.x>>b.y>>c.x>>c.y;

    int A = c.y - b.y;
    int B = b.x - c.x;
    int C = -A*b.x - B*b.y;
    cout<<A<<" "<<B<<" "<<C<<"\n";
}