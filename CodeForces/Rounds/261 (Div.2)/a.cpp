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

    pii a, b, c, d;
    cin>>a.f>>a.s>>b.f>>b.s;

    int dx = abs(a.f - b.f), dy = abs(a.s - b.s);
    if(dx && dy && (dx != dy)) {
    	cout<<"-1\n";
    } else {
    	int k = dx + dy;
		if(dx == 0) {
			c = {a.f + k, a.s};
			d = {b.f + k, b.s};
		} else if(dy == 0) {
			c = {a.f, a.s + k};
			d = {b.f, b.s + k};
		} else {
			c = {b.f, a.s};
			d = {a.f, b.s};
		}

	    cout<<c.f<<" "<<c.s<<" "<<d.f<<" "<<d.s<<"\n";    	
    }
}