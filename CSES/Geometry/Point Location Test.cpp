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
	ll x, y;
	void read(){cin>>x>>y;}
};

ll dot(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

void solve_task()
{
	point a,b, k;
	a.read();
	b.read();
	k.read();

	point v1, v2;
	v1.x = a.x - b.x;
	v1.y = a.y - b.y;

	v2.x = k.x - b.x;
	v2.y = k.y - b.y;

	ll prod = dot(v1, v2);
	
	if(prod < 0)
		cout<<"LEFT";
	else if(prod == 0)
		cout<<"TOUCH";
	else
		cout<<"RIGHT";
	cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}