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

    int n, m;
    cin>>n>>m;
    multiset<int> tickets;

    for(int i=0;i<n;++i) {
    	int x;
    	cin>>x;
    	tickets.insert(x);
    }
    int inf = 1e9 + 10;
    tickets.insert(-inf);
    tickets.insert(inf);

    for(int i=0;i<m;++i) {
    	int x;
    	cin>>x;
    	auto it = tickets.upper_bound(x);
    	it--;

    	if(it == tickets.begin()) {
    		cout<<"-1\n";
    	} else {
    		cout<<*it<<"\n";
    		tickets.erase(it);
    	}
    }
}