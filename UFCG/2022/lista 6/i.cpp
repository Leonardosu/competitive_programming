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

const int N = 3e5 + 7;
const int inf = 1e9;

int jump[N], slide[N], nxt[N];
int n, moves[N];
pii prv[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i) 
		cin>>jump[i];
	for(int i=1;i<=n;++i) 
		cin>>slide[i];
	
	for(int i=0;i<=n+1;++i)
		moves[i] = inf;

	set<int> remain;
	for(int i=0;i<=n;++i)
		remain.insert(i);
	remain.insert(n+1);

	queue<int> fila;
	fila.push(n);
	moves[n] = 0;

	// x -> y
	while(!fila.empty()) {
		int x = fila.front(); fila.pop();

		while(1) {
			int pos = *remain.lower_bound(x - jump[x]);
			if(pos > x) break;

			remain.erase(pos);
			int cost = moves[x] + 1; 
			int y = pos + slide[pos];
			if(moves[y] > cost) {
				moves[y] = cost;
				prv[y] = {x, pos};
				fila.push(y);
			}
		}
	}

	if(moves[0] == inf) {
		cout<<-1;
	} else {
		int x = 0;
		vector<int> ans;
		while(x != n) {
			ans.pb(prv[x].s);
			x = prv[x].f;
		}

		reverse(ALL(ans));
		cout<<ans.size()<<"\n";
		for(int &x : ans)
			cout<<x<<" ";
	}
	cout<<"\n";
}