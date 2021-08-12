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


// x/y

// struct point
// {
// 	int x,y;	
// 	point(int x_,int y_)
// 	{
// 		x = x_;
// 		y = y_;
// 	}
// };


ll solve(map<long double,ll> &freq)
{
	ll best = 0,curr = 0;

	for(auto &it : freq)
	{
		curr += it.second;
		if(curr < 0)
			curr = 0;

		best = max(best,curr);
	}

	return best;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	int n;
	cin>>n;

	vector<pair<long double,ll>> v(n);

	ll a,b,c,d;
	// int x= 0,y = 0;

	map<long double,ll> freq1,freq2;

	ll total = 0LL;
	for(int i=0;i<n;++i)
	{
		cin>>a>>b>>c>>d;

		long double angle = atan2(a,b);
		
		total += c - d;
		freq1[angle] += (c-d);
		freq2[angle] += (d-c);
	}

	cout<<max(solve(freq1), total + solve(freq2))<<"\n";

	// cout<<x<<" , "<<y<<"\n";
}
