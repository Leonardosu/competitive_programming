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
	void r(){cin>>x>>y;}
};

void solve_task()
{
	array<pt, 3> pts;
	for(int i=0;i<3;++i)
		pts[i].r();

	double ans = 0;
	for(int i=0;i<3;++i)
	{
		int j = (i+1)%3, k = (i+2)%3;
		if(pts[i].y == 0)
			continue;
		if(pts[i].y == pts[j].y && pts[k].y < pts[i].y)
			ans += abs(pts[i].x - pts[j].x);
	}

	cout<<fixed<<setprecision(10);
	cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}