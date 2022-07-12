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

ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
struct UnionFind {
    vector<int> parent, level;
    UnionFind(int numberNodes) {
        parent.resize(numberNodes + 1);
        level.resize(numberNodes + 1);
        for(int i=0;i<=numberNodes;++i)
            parent[i] = i, level[i] = 0;            
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(level[x] < level[y]) swap(x,y);
        if(level[x] == level[y]) level[x]++;
        parent[y] = x;
    }
};

struct SegmentTree {
	int *st;
 	int n;

	SegmentTree(int arr[], int n_) {
		n = n_;
	   	int height = (int)(ceil(log2(n)));
	   	int size = 2*(int)pow(2, height)-1;
	   	st = new int[size];
	   	build(0, arr, 0, n-1);
	}

	int build(int no, int arr[], int ss, int se) {
	    if (ss==se) {
	        st[no] = arr[ss];
	        return st[no];
	    }
	    int mid = ss+(se-ss)/2;
	    st[no] = gcd(build(no*2+1, arr, ss, mid),
	                 build(no*2+2, arr, mid+1, se));
	    return st[no];
	}

	int findGcd(int no, int ini, int fim, int L, int R) {
	    if (ini>R || fim < L)
	        return 0;
	    if (L<=ini && R>=fim)
	        return st[no];

	    int mid = (fim+ini)/2;
	    return gcd(findGcd(no*2+1, ini, mid, L, R),
	               findGcd(no*2+2, mid+1, fim, L, R));
	}
	 
	int query(int L, int R) {
		assert(L<=R);
		assert(L>=0 && L<=n-1);
		assert(R>=0 && R<=n-1);
	    return findGcd(0, 0, n-1, L, R);
	}
};

void solve_task()
{
	int n, p;
	cin>>n>>p;

	int v[n];
	for(int i=0;i<n;++i)
		cin>>v[i];

	SegmentTree st = SegmentTree(v, n);
	cout<<st.query(0, n-1)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}