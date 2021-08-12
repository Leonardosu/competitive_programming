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
inline ll poww(ll a, ll b){ll res = 1;while (b > 0){if(b & 1) res = (res * a);a = (a * a);b >>= 1;}return res;}
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string number;
	cin>>number;

	ll x = 0;
	ll y = 100;

	int pot = 0;
	bool flag = false;

	for(int i=0;i<number.size();++i)
	{
		if(number[i] == '.')
			flag = true;
			
		else
		{			
			x*=10,x += number[i] - '0';
			if(flag)
				y *= 10;
		}
	}

	pot = number.size();
	// ll y = poww(10,pot);
	ll k = gcd(x,y);
	// cout<<x<<" / "<<y<<" -> "<<k<<"\n";

	y /= k;
	x /= k;

	
	cout<<y<<"\n";

}
