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

struct point{
	int x, y;
};

void solve_task()
{
	point b;
	cin>>b.x>>b.y;	

	for(int x=0;x<=50;++x)
		for(int y=0;y<=50;++y)
		{
			if(abs(x) + abs(y) == abs(b.x - x) + abs(b.y - y))
			{
				cout<<x<<" "<<y<<"\n";
				return;
			}
		}
	cout<<"-1 -1\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	while(T_T--)
		solve_task();
}