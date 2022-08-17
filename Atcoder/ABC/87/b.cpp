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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a, b, c, x;
	cin>>c>>b>>a>>x;
	/*
	10, 2, 1 = k
	k = 1.x + 2.y + 10.z
	x <= a
	y <= b
	z <= c
	*/
	ll ans = 0;
	// x /= 50;
	for(int i=0;i<=a;++i) {
		for(int j=0;j<=b;++j) {
			for(int k=0;k<=c;++k)
				if(i*50 + 100*j + 500*k == x)
					ans++;
		}
	}
	cout<<ans<<"\n";
}