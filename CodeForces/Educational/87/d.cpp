#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct BIT {
    using T = long long int;
    vector<T> bit;
    int N;
    BIT(int n) {
        N = n + 2;
        bit.resize(n + 2);            
    }
    
    void update(int x, T val = 1) {
        x++;
        while(x < N)
            bit[x] += val, x += x&(-x);
    }    
    int query(int x) {
        if(x <= 0) return 0;
        x++;
        T sum = 0;
        while(x > 0)
            sum += bit[x], x -= x&(-x);
        return sum;
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n, q;
    cin>>n>>q;
    const int N = 1e6 + 10;
    BIT bit(N);

    for(int i=1;i<=n;++i) {
    	int x;
    	cin>>x;
    	bit.update(x, 1);
    }

    int cnt = n;
    while(q--) {
    	int x;
    	cin>>x;
    	if(x > 0) {
    		bit.update(x, 1);
    		cnt++;
    	} else {
    		x = -x;
    		int l = 0, r = n;
    		while(r-l>1) {
    			int mid = (l+r)/2;
    			if(bit.query(mid) >= x) {
    				r = mid;
    			} else {
    				l = mid;
    			}
    		}
    		bit.update(r, -1);
    		cnt--;
    	}
    }

    if(!cnt) {
    	cout<<"0\n";
    } else {
    	int x = 0;
    	while(x<=n && !bit.query(x))
    		x++;
    	cout<<x<<endl;
    }

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}