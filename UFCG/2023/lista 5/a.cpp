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

struct node {
	node *l = this, *r = this;
	int val = 0;
	node(){}
};


node* update(node *curr, int ini, int fim, int pos, int v) {
	node *root = new node();

	if(ini == fim) {
		root->val = curr->val + 1;
		return root;
	}

	int mid = (ini+fim)/2;
	if(pos <= mid) {
		root->l = update(curr->l, ini, mid, pos, v);
		root->r = curr->r;
	} else {
		root->l = curr->l;
		root->r = update(curr->r, mid+1, fim, pos, v);
	}

	root->val = root->l->val + root->r->val;
	return root;
}

int query(node *curr, int ini, int fim, int l, int r) {
	if(fim < l || ini > r) return 0;
	if(l<=ini && fim<=r) return curr->val;

	int mid = (ini+fim)/2;
	return query(curr->l, ini, mid, l, r) + query(curr->r, mid+1, fim, l, r); 
}


int query(node *L, node *R, int ini, int fim, int k) {
	if(ini == fim) return ini;

	int cnt = R->l->val - L->l->val;
	int mid = (ini+fim)/2;

	if(cnt >= k) {
		return query(L->l, R->l, ini, mid, k);
	} else {
		return query(L->r, R->r, mid+1, fim, k-cnt);
	}
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    vi v(n);
    for(auto &x : v)
    	cin>>x;


    vi tmp = v;
    sort(all(tmp));
    tmp.resize(unique(all(tmp)) - (tmp).begin());
    vector<node*> versoes;
    versoes.pb(new node());

    for(auto x : v) {
    	int pos = (lower_bound(all(tmp), x) - (tmp).begin()) + 1;

    	auto new_root = update(versoes.back(), 1, n, pos, 1);
    	versoes.pb(new_root);
    }

    while(m--) {
    	int l,r,k;
    	cin>>l>>r>>k;

    	auto L = versoes[l-1], R = versoes[r];
    	auto ans = query(L, R, 1, n, k);

    	cout<<tmp[ans-1]<<"\n";
    }
}