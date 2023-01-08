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
	int x, y;
	bool blue;
	pt(int x_=0,int y_=0, bool isBlue = false) : x(x_), y(y_), blue(isBlue) {}
};

bool cmp(pt &a, pt &b) {
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<pt> v;
    int n, x, y;
    cin>>n;
    for(int i=0;i<n;++i) {
    	cin>>x>>y;
    	v.pb(pt(x,y,false));
    }

    for(int i=0;i<n;++i) {
    	cin>>x>>y;
    	v.pb(pt(x,y,true));
    }

    sort(ALL(v), cmp);
    map<int,int> qnt;
 	int ans = 0;

 	for(auto q : v) {
 		if (q.blue) { 			
 			if(qnt.size() == 0) continue;

 			auto it = qnt.lower_bound(q.y);
 			if(it == qnt.begin()) continue;
 			it = prev(it);
 			ans++;

 			qnt[it->first]--;
 			if(it->second == 0)
 				qnt.erase(it->first);			 
 		} else {
 			qnt[q.y]++;
 		}
 	}

 	cout<<ans<<"\n";
}