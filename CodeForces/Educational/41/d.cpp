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

const int maxn = 1e5 + 7;
int n;
ll x[maxn],y[maxn];

bool colinear(int a,int b,int c) {
	ll area = x[a]*y[b] + x[b]*y[c] + x[c]*y[a]
			- y[a]*x[b] - y[b]*x[c] - y[c]*x[a];
	return (area == 0);
}

bool check(int a,int b) // uma das retas eh formada por AB
{
	bool vis[maxn];
	memset(vis, false, sizeof(vis));
	int qnt = 0, c = -1, d = -1;

	for(int i=1;i<=n;++i) {
		if(colinear(a,b,i)) {
			vis[i] = true;
			qnt++;
		} else {
			if(c == -1) c = i;
			else d = i;
		}
	}

	for(int i=1;i<=n;++i)
		if(!vis[i] && colinear(c,d,i)) {
			vis[i] = true;
			qnt++;
		}

	if(qnt == n) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;++i) 
		cin>>x[i]>>y[i];

	if(n <= 4) {
		cout<<"YES\n";
		return 0;
	}

	bool can = check(1,2) | check(1,3) | check(2,3);
	cout<<(can ? "YES" : "NO")<<"\n";
}