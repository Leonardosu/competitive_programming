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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    using event = pair<int,int>;
    vector<event> events;
    for(int i=0;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	events.pb({x, 1});
    	events.pb({y+1, -1});
    }

    sort(ALL(events));
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<sz(events);++i) {
    	int x = events[i].f;
    	cnt += events[i].s;
		ans = max(ans, cnt);    	

    	while(i+1 < sz(events) && events[i+1].f == x) {
    		i++;
    		cnt += events[i].s;
    		ans = max(ans, cnt);    	    		
    	}
    }

    ans = max(ans, cnt);
    cout<<ans<<"\n";
}