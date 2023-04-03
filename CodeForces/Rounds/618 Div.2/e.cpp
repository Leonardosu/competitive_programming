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

using ld = long double;
const int N = 1e6 + 7;
struct node {
	int l, r;
	ll sum;
};

ll v[N];
ld ans[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    
    for(int i=1;i<=n;++i) {
    	cin>>v[i];
    }
    
	stack<node> pilha;
	pilha.push({1, 1, v[1]});
    for(int i=2;i<=n;++i) {
    	node now = {i, i, v[i]};
    	while(!pilha.empty()) {
    		// a1/b1 <= a2/b2
    		// a1*b2 <= a2*b1
    		ll a1 = now.sum;
    		ll b1 = now.r - now.l + 1;
    		auto last = pilha.top();
    		pilha.pop();

    		ll a2 = last.sum;
    		ll b2 = last.r - last.l + 1;
    		if(a1*b2 <= a2*b1) {
    			now.sum += last.sum;
    			now.l = min(last.l, now.l);
    			now.r = max(last.r, now.r);
    		} else {
    			pilha.push(last);
    			break;
    		}
    	}
    	pilha.push(now);
    }

    while(!pilha.empty()) {
    	auto now = pilha.top();
    	pilha.pop();
    	for(int i=now.l;i<=now.r;++i) {
    		ans[i] = (1.0 * now.sum) / (now.r - now.l + 1);
    	}
    }

    cout<<fixed<<setprecision(10);
    for(int i=1;i<=n;++i)
    	cout<<ans[i]<<"\n";
}