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

struct pt {
	ll x,y;	
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<pt> points;
    for(int i=0;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	points.pb({x,y});
    }

    if(n%2 == 1) {
    	cout<<"NO\n";
    } else {
    	vector<pt> midpoints;

    	for(int i=0;i<n;++i) {
    		ll dx = points[(i+1)%n].x - points[i].x;
    		ll dy = points[(i+1)%n].y - points[i].y;
    		midpoints.pb({dx, dy});
    	}

    	int i = 0, j = n/2;
    	map<pair<ll,ll>,int> freq;
	  	for(;i<n/2;++i,++j) {
	  		ll dx = midpoints[i].x + midpoints[j].x;
	  		ll dy = midpoints[i].y + midpoints[j].y;
	  		freq[{dx, dy}]++;
    	}
    	cout<<(freq.size() == 1 ? "YES" : "NO")<<"\n";
    }
}