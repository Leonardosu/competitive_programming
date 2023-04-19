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
        root->val = curr->val + v;
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

int query(node *curr, int ini, int fim, int k) {
    if(ini == fim) return ini;

    int cnt = curr->l->val;
    int mid = (ini+fim)/2;

    if(cnt <= k) {
        return query(curr->r, mid+1, fim, k-cnt);
    } else {
        return query(curr->l, ini, mid, k);        
    }
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    vi v(n);
    for(auto &x : v)
        cin>>x;

    vector<node*> versoes;
    versoes.pb(new node());
    map<int,int> lastPos;

    int i = 1;
    for(auto x : v) {
        auto atual = update(versoes.back(), 0, n+1, i, 1);
        
        if(lastPos.count(x) != 0) {
            atual = update(atual, 0, n+1, lastPos[x], -1);
        }

        versoes.pb(atual);
        lastPos[x] = i--;
    }

    // reverse(versoes.begin() + 1, versoes.end());
    for(int k=1;k<=n;++k) {
        int i = 1;
        int groups = 0;

        while(i<=n) {
            int nextPos = query(versoes[i], 0, n+1, k);
            groups++;
            i = nextPos;
        }        
        cout<<groups<<" ";  
    }

}