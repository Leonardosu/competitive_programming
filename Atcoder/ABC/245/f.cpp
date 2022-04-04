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

const int N = 2e5 + 7;
int in[N], out[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin>>n>>m;
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));

	vector<int> g[n+1];
	for(int i=0;i<m;++i)
	{
		int a,b;
		cin>>a>>b;
		out[a]++;
		g[b].pb(a);
	}

	queue<int> q;
	for(int i=1;i<=n;++i)
		if(!out[i])
			q.push(i);

	while(!q.empty())
	{
		int x = q.front(); q.pop();
		n--;
		for(int &y : g[x])
		{
			out[y]--;
			if(!out[y])
				q.push(y);
		}
	}

	cout<<n<<"\n";
}
