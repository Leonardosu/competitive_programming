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

int tab[5000][5000];
int gcd(int x, int y) {
  if (x < y) swap(x, y);
  if (x < 5000) return tab[x][y];
  if (y == 0) return x;
  return gcd(y, x % y);
}

struct SegmentTree {
	int *st;
	int qnt, n;

	#define left 2*no+1
	#define right 2*no+2

	SegmentTree(vector<int> &arr, int n_) {
		n = n_;

		int height = (int)(ceil(log2(n)));
	   	int size = 2*(int)pow(2, height);
	   	st = new int[size];
	   	memset(st, 0, sizeof st);
	   	build(0, arr, 0, n-1);
	}

	void build(int no, vector<int> &arr, int ini, int fim) {
	    if (ini == fim) {
	        st[no] = arr[ini];
	    } else {
		    int mid = (fim+ini)>>1;
		    build(left, arr, ini, mid);
		    build(right, arr, mid+1, fim);

		    st[no] = gcd(st[left], st[right]);
	    }
	}

	void query(int no, int ini, int fim, int L, int R, int x) {
	    if (!(st[no]%x))
	        return;

	    if (L<=ini && R>=fim) {
	    	if(qnt == 2) return;

	    	if(ini == fim) {
	    		qnt++;
	    	} else {
	    		int mid = (fim+ini)>>1;
			    query(left, ini, mid, L, R, x);
			    query(right, mid+1, fim, L, R, x);
	    	}
	    } else {
	    	int mid = (fim+ini)>>1;
			if (L<=mid) query(left, ini, mid, L, R, x);
			if (mid<R) query(right, mid+1, fim, L, R, x);
	    }
	}

	void update(int no, int ini, int fim, int pos, int x) {
		if(ini == fim) {
			st[no] = x;
		} else {
			int mid = (ini+fim)>>1;
			pos <= mid ? 	update(left, ini, mid, pos, x) : 
							update(right, mid+1, fim, pos, x);

			st[no] = gcd(st[left], st[right]);
		}
	}

	bool almostCorrect(int L, int R, int x) {
		qnt = 0;
		query(0, 0, n-1, L, R, x);
		return qnt < 2;
	}

};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j <= i; j++) {
			tab[i][j] = (j == 0 ? i : tab[j][i % j]);
		}
	}
	int n, q;
	cin>>n;

	vector<int> v(n);
	for(int &x : v)
		cin>>x;

	SegmentTree segtree(v, n);
	cin>>q;

	while(q--){
		int t, l, r, x;
		cin>>t;
		if(t == 1) {
			cin>>l>>r>>x;
			cout<<(segtree.almostCorrect(l-1, r-1, x) ? "YES" : "NO")<<"\n";
		} else {
			cin>>r>>x;
			segtree.update(0, 0, n-1, r-1, x);
		}
	}
}