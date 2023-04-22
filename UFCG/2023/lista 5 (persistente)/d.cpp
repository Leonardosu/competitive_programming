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
};

node* update(node *curr, int ini, int fim, int pos, int v) {
    node *root = new node();
    if(ini == fim) {
        root->val = curr->val + v;
    } else {
        int mid = (ini+fim)>>1;
        if(pos <= mid) {
            root->l = update(curr->l, ini, mid, pos, v);
            root->r = curr->r;
        } else {
            root->l = curr->l;
            root->r = update(curr->r, mid+1, fim, pos, v);
        }
        root->val = root->l->val + root->r->val;
    }

    return root;
}

int query(node *curr, int ini, int fim, int l, int r) {
    if(fim < l || ini > r) return 0;
    if(l<=ini && fim<=r) return curr->val;

    int mid = (ini+fim)>>1;
    return query(curr->l, ini, mid, l, r) + query(curr->r, mid+1, fim, l, r); 
}
vector<node*> versoes = {new node()};


const int N = 100005;
queue<int> mostLeft[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin>>n>>k;

    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;

        versoes.pb(update(versoes.back(), 1, n, i, 1));
        mostLeft[x].push(i);        

        if(sz(mostLeft[x]) > k) {
            int left = mostLeft[x].front();
            mostLeft[x].pop();
            versoes.back() = (update(versoes.back(), 1, n, left, -1));
        }
    }
    

    int m;
    cin>>m;

    int last = 0;
    while(m--) {
        int l,r;
        cin>>l>>r;

        l = (l+last)%n + 1;
        r = (r+last)%n + 1;
        if(l > r) swap(l,r);

        last = query(versoes[r], 1, n, l, r);
        cout<<last<<endl;
    }
}