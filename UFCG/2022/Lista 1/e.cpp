#include "bits/stdc++.h" //Multiple Testcases
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

vector<vector<int>> ans;
const int N = 2e5 + 7;
int qnt[N], c[N];
int n, k;

bool check(int limit)
{
	ans.resize(limit);
	for(int i=0;i<limit;++i)
		ans[i].clear();

	int id = 0;
	for(int val=k;val>=1;--val)	
	{
		for(int j=0;j<qnt[val];++j)
		{
			ans[id].pb(val);
			if(ans[id].size() > c[val]) 
				return false;
			id++;
			if(id == limit)
				id = 0;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;

	for(int i=0, x;i<n;++i)
	{
		cin>>x;
		qnt[x]++;
	}

	for(int i=1;i<=k;++i)
		cin>>c[i];	

	int l = 1, r = n, id = n;
	while(l <= r)
	{
		int mid = (l + r)/2;
		if(check(mid))
			id = mid, r = mid - 1;
		else
			l = mid + 1;
	}

	check(id);
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();++i)
	{
		cout<<ans[i].size()<<" ";
		for(int &x : ans[i])
			cout<<x<<" ";
		cout<<"\n";
	}
}