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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x;
	cin>>n>>x;

	queue<int> q;
	q.push(0);
	bool can = false;
	
	for(int i=0;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		int len = q.size();
		bool vis[x+1];
		memset(vis, false, sizeof vis);

		for(int j=0;j<len;++j)
		{
			int pos = q.front(); q.pop();

			if(pos + a <= x && !vis[pos + a])
			{
				vis[pos + a] = true;
				q.push(pos + a);
				if(i == n-1 && pos + a == x)
					can = true;
			}
			if(pos + b <= x && !vis[pos + b])
			{
				vis[pos + b] = true;
				if(i == n-1 && pos + b == x)
					can = true;
				q.push(pos + b);
			}
		}
	}

	cout<<(can ? "Yes" : "No")<<"\n";
}