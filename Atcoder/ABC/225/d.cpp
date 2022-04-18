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

const int N = 1e5 + 2;
int parent[N];
vector<set<int>> filhos(N);
vector<int> ans;

void go(int x)
{
	ans.pb(x);
	if(filhos[x].empty())
		return;

	for(auto &y : filhos[x])
	{
		go(y);
	}
}

int findRoot(int x)
{
	if(parent[x] == -1)
		return x;
	return findRoot(parent[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    	parent[i] = -1;

    while(q--)
	{
		int t, x, y;
		cin>>t;
		if(t == 1)
		{
			cin>>x>>y;
			parent[y] = x;
			filhos[x].insert(y);
		}
		else if(t == 2)
		{
			cin>>x>>y;
			parent[y] = -1;
			filhos[x].erase(y);
		}
		else
		{
			cin>>x;
			ans.clear();
			x = findRoot(x);
			
			go(x);
			cout<<ans.size()<<" ";

			for(int &y : ans)			
				cout<<y<<" ";
			cout<<"\n";
		}
	}
}