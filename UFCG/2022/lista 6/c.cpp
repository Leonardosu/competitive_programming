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

int gcd(int a, int b) { while (b) { a %= b,swap(a, b);}return a;}
int menor(int a, int b) {return min(a,b);}
const int N = 2e5 + 7;
int v[N];

struct SparseTable{
    vector<vector<int>> sp;
    vector<int> val;
    SparseTable(vector<int> &_a, int (*function)(int,int)){
    	val = _a;

        int n = val.size(), size = __lg(n) + 1;
        sp.resize(n, vector<int>(size));

        for (int i=n-1; i>=0; i--){
            sp[i][0] = val[i];
            for (int j=1; i+(1<<j)<=n; j++){
                sp[i][j] = function(sp[i][j - 1], sp[i + (1 << j - 1)][j - 1]);
            }
        }
    }

    int query(int l, int r, int (*function)(int,int)){
        int k = __lg(r - l);
        return function(sp[l][k], sp[r - (1 << k)][k]);
    }
};


void solve_task()
{
	int n, p;
	cin>>n>>p;

	vector<int> v(n);
	for(int &x : v)
		cin>>x;

	SparseTable sparseMin(v, &menor);
    SparseTable sparseGcd(v, &gcd);
	vector<int> qry[n];

	for(int i=0;i<n;++i) {
		//leftmost
		int pos = i;
		int l = -1, r = i;
		while(l + 1< r) {
			int mid = (l + r + 1) >> 1;
			if(sparseMin.query(mid,  i + 1, &menor) != v[i] || sparseGcd.query(mid, i + 1, &gcd) != v[i])
				l = mid;
			else
				r = mid, pos = mid;
		}
		qry[pos].pb(v[i]);

		//rightmost
		pos = i;
		l = i, r = n ;
		while(l + 1 < r) {
			int mid = (l + r) >> 1;
			if(sparseMin.query(i,  mid + 1, &menor) != v[i] || sparseGcd.query(i, mid + 1, &gcd) != v[i])
				r = mid;
			else
				l = mid, pos = mid;
		}
		qry[pos].pb(-v[i]);
	}

	qry[0].pb(p);
	qry[n-1].pb(-p);

	ll ans = 0;	
    multiset<int> st;
    for (int i=0; i<n-1; i++){
        for (auto x: qry[i]){
            if (x > 0)
                st.insert(x);
            else
                st.erase(st.find(-x));
        }
        ans += *st.begin();
    }
	cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}