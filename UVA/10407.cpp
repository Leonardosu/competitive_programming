#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> v;
ll qnt,x;
ll ans;
bool stop = false;
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while(cin>>x)
	{
		if(x == 0)
		{
			if(stop) break;
			stop = true;
			ans = abs(v[1] - v[0]);
			int n = v.size();
			for(int i=0;i<n-1;++i)
				ans = gcd(abs(v[i+1] - v[i]),ans);
			cout<<ans<<"\n";
			v.clear();
		}
		else
		{
			v.push_back(x);
			stop = false;			
		}
	}
	return 0;
}