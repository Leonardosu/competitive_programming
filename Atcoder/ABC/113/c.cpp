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
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    int pai[m+1], ordem[m+1];
   	vector<pii> g[n+1];
   	for(int i=1;i<=m;++i) {
   		int p, y;
   		cin>>p>>y;
   		pai[i] = p;
   		g[p].pb({y, i});
   	}

   	for(int i=0;i<=n;++i) {
   		if(!g[i].empty()) {
   			sort(all(g[i]));

   			for(int j=0;j<sz(g[i]);++j) {
   				int id = g[i][j].s;
   				ordem[id] = j + 1;
   			}
   		}
   	}

   	auto add = [](string &s) {
   		int falta = 6 - sz(s);
   		if(falta <= 0) return;

   		string tmp = string(falta, '0');
   		s.insert(0,tmp);
   	};

   	for(int i=1;i<=m;++i) {
   		string left = to_string(pai[i]);
   		add(left);
   		string right = to_string(ordem[i]);
   		add(right);
   		cout<<left<<right<<"\n";
   	}
}