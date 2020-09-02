#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


ll power(ll x,ll n)
{
    ll result = 1LL;
    while(n)
    {
        if(n & 1)
            result *= x;
        x *= x;
        n /= 2LL;
    }
    return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	vector<ll> v(n);

	ll now = 0,best = -n;
	for(int i=0;i<n;++i) 
	{
		cin>>v[i];
		best += v[i];
	}	
	
	sort(all(v));

	ll x = 2e5 + 125;
	// while(power(x,n-1) <= 1e15)
	// 	x++;

	for(ll c = 2;c<=x;++c)
	{
		now = 0LL;
		ll valor = 1LL;

		for(int i=0;i<n;++i)
		{
			if(now >= best) break;
			now += abs(v[i] - valor);
			valor*=c;
		}		
		best = min(best,now);
	}

	cout<<best<<"\n";
		
}
/*
1999982505 :
1000000000 
 999982505
*/