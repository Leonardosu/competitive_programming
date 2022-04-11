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


const int MAXK = 31;
const int INF = (1<<30);

struct node{
	int pos, val;
	node(int pos_ = INF, int val_ = INF) : pos(pos_), val(val_) {}
	bool operator<(const node& p) const {return (val < p.val);}
};

struct SegTree{
	vector<node> tree;
	SegTree(int n, vector<int> &v){
		tree.resize(n*4);
		for(int i=1;i<=n;++i)
			update(1, 1, n, i, v[i]);
	}

	void update(int no, int tl, int tr, int pos, int val)
	{
		if(tl == tr)
			tree[no] = node(pos, val);
		else
		{
			int mid = (tl+tr)/2;
			if(pos <= mid)
				update(2*no, tl, mid, pos, val);
			else
				update(2*no+1, mid+1, tr, pos, val);

			tree[no] = min(tree[no*2], tree[no*2 + 1]);
		}
	}

	node query(int no, int tl, int tr, int l, int r)
	{
		if(l<=tl && tr<=r)
			return tree[no];
		int mid = (tl + tr)/2;
		if(r <= mid)
			return query(no*2, tl, mid, l, r);
		else if(l > mid)
			return query(no*2 + 1, mid + 1, tr, l, r);
		else
			return min(query(no*2, tl, mid, l, r), query(no*2+1, mid+1, tr, l, r));
	}
};

void solve_task()
{
	int n, q;
	cin>>n;
	vector<int> v(n+1);
	for(int i=1;i<=n;++i)
		cin>>v[i];
	SegTree sg = SegTree(n, v);

	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;

		vector<node> caras;
		for(int i=0;i<min(r - l + 1, MAXK+1);++i)
		{
			node curr = sg.query(1, 1, n, l, r);
			caras.pb(curr);
			sg.update(1, 1, n, curr.pos, INF);
		}

		int ans = (1LL << 31) - 1;
		for(int i=0;i<(int)caras.size();++i)
			for(int j=i+1;j<(int)caras.size();++j)
				ans = min(ans, caras[i].val | caras[j].val);

		for(node &curr : caras)
			sg.update(1, 1, n, curr.pos, curr.val);
		cout<<ans<<"\n";
	}
}	

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}