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

const int totalPeriod = 10;
struct shop{
	bool open[totalPeriod];
	void readInput() {
		for(int i=0;i<totalPeriod;++i)
			cin>>open[i];
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	vector<shop> shops(n);
	vector<array<ll, totalPeriod + 1>> profits(n);

	for(int i=0;i<n;++i)
		shops[i].readInput();

	ll ans = LONG_MIN;
	for(int i=0;i<n;++i) {
		for(int j=0;j<=totalPeriod;++j) 
			cin>>profits[i][j];
	}
	
	for(int bitmask=1;bitmask<(1<<totalPeriod);++bitmask) {
		bool atLeastOneDay = 0;
		ll profit = 0;

		for(int i=0;i<n;++i) {
			int daysOpen = 0;
			for(int period=0;period<totalPeriod;++period) {
				daysOpen += (bitmask & (1<<period)) && (shops[i].open[period]);
			}
			
			profit += profits[i][daysOpen];
			atLeastOneDay |= daysOpen;
		}

		if(atLeastOneDay) {
			ans = max(ans, profit);
		}		
	}

	cout<<ans<<"\n";
}