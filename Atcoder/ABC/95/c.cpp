#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a,b,ab,x,y;
	cin>>a>>b>>ab>>x>>y;
	ll total = 0;

	if(2LL*ab <= a + b)
	{
		ll k = min(x,y);
		total = 2LL*ab*(k);
		x-=k;
		y-=k;
	}

	if(2LL*ab <= a)
		total += 2LL*ab*x,x = 0;
	if(2LL*ab <= b)
		total += 2LL*ab*y,y = 0;

	total += x*a + y*b;
	cout<<total<<"\n";
}