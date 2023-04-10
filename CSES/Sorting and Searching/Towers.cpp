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
 
 
int lis(vector<int> v) {
	int n = sz(v);
	if(n == 0) return 0;
 
	vector<int> pilha(n, 0);
	int id = 0;
	// pilha[0] = v[0];
 
	for(int x : v) {
		auto it = upper_bound(pilha.begin(), pilha.begin() + id, x);
		if(it == pilha.begin() + id)
			pilha[id++] = x;
		else
			*it = x;
	}
 
	return id;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n;
    cin>>n;
    vi v(n);
    for(int &x : v)
    	cin>>x;
 
    cout<<lis(v)<<"\n";
}