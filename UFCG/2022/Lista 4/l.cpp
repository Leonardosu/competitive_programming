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

void generateAllSum(vector<ll> &v, set<ll> &exist, ll mod)
{
	int n = v.size();
	for(int bitmask=0;bitmask<(1<<n);++bitmask)
	{
		ll sum = 0;
		for(int i=0;i<n;++i)
			if(bitmask & (1<<i))
			{
				sum += v[i];
				if(sum > mod)
					sum -= mod;
			}
		exist.insert(sum);
	}
}

ll getBest(set<ll> &a, set<ll> &b, ll mod)
{
	ll best = 0;
	ll biggest = *b.rbegin();
	ll smallest = *b.begin();
	for(auto x : a)
	{
		// x + y <= mod
		//x + y
		// mod - x
		ll target = mod - x - 1;
		auto it = b.upper_bound(target);
		it--;
		if(it != b.end())
		{
			ll sum = (x + *it)%mod;
			if(sum > best)
			{
				// cout<<x<<" + "<<*it<<"\n";
				best = max(best, sum);		
			}
		}
		best = max({best, (x + biggest)%mod, (x + smallest)%mod});
	}	
	return best;
}


void solve_task()
{
	ll n, mod;
	cin>>n>>mod;

	vector<ll> left, right;
	ll x;
	for(int i=0;i<n/2;++i)
	{
		cin>>x;
		// cout<<"~ "<<x<<"~\n";
		left.pb(x);
	}

	for(int i=n/2;i<n;++i)
	{
		cin>>x;
		right.pb(x);
	}

	set<ll> leftSum, rightSum;

	generateAllSum(left, leftSum, mod);
	generateAllSum(right, rightSum, mod);

	cout<<max(getBest(leftSum, rightSum, mod), getBest(rightSum, leftSum, mod))<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    // cin>>T_T;
    while(T_T--)
        solve_task();
}