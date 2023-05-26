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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int N = 1e5 + 7;
    BIT bt = BIT(N);

    int n, ans = 0;
    cin>>n;
    
    for(int i=0;i<n;++i) {
    	int x;
    	cin>>x;
    	int qnt = bt.query(x - 1) + 1;
    	ans = max(ans, qnt);
    	bt.update(x, qnt);
    }

    cout<<ans<<"\n";
}