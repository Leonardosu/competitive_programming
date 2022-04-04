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

struct Event{
	ll win, lose;
	bool winNormal, winTroll;

	ll playNormal()
	{
		return (winNormal ? win : -lose);
	}

	ll playTroll()
	{
		return (winTroll ? win : -lose);	
	}
};

int n;
vector<Event> events;
ll low, high;

map<pair<ll,ll> , ll> dp;

ll solve(int i, ll rating)
{
	if(i == n)
		return rating;

	if(dp.count({i, rating}))
		return dp[{i, rating}];

	ll go = 0;
	Event event = events[i];

	if(rating < low)
		go = solve(i+1, rating + event.playNormal());
	else if(high < rating)
		go = solve(i+1, rating + event.playTroll());	
	else
	{
		ll normal = solve(i+1, rating + event.playNormal());
		ll troll =  solve(i+1, rating + event.playTroll());
		go = max(normal, troll);
	}

	return dp[{i, rating}] = go;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll k, rating;
	cin>>n>>k>>rating;

	low = rating - k, high = rating + k;

	for(int i=0;i<n;++i)
	{
		Event event;
		cin>>event.win>>event.lose>>event.winNormal>>event.winTroll;
		events.pb(event);
	}

	cout<<solve(0LL, rating)<<"\n";
}