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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    vi v(n);
    for(auto &x : v)
    	cin>>x;

    auto bruto = [&](int k) {
    	int cnt[n+1];
    	memset(cnt, 0, sizeof cnt);

    	int groups = 1, curr = 0, start = 0;
    	for(int i=0;i<n;++i) {
    		int x = v[i];
    		curr += (cnt[x] == 0);

    		if(curr > k) {
    			groups++;
    			curr = 1;
    			while(start < i) 
    				cnt[v[start]]--, start++;
    		}
    		cnt[x]++;
    	}
    	return groups;
    };


    int ans[n+1];
    memset(ans, -1, sizeof ans);

    ans[1] = bruto(1);
    ans[n] = 1;
    stack<pii> pilha;

    pilha.push({1, n});
    while(!pilha.empty()) {
    	auto [l, r] = pilha.top();
    	pilha.pop();

    	if(ans[l] == ans[r]) {
    		while(l<r) 
    			ans[l++] = ans[r];    		
    	} else if(r-l>1){
    		int mid = (l+r)/2;
    		ans[mid] = bruto(mid);

    		pilha.push({mid,r});
    		pilha.push({l, mid});
    	}
    }

    for(int i=1;i<=n;++i)
    	cout<<ans[i]<<" ";
}