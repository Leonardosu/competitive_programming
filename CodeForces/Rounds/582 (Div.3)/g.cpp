#include <bits/stdc++.h> //DSU + offline queries
#define f first			// Leonardo su 
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
 
const int N = 200010;
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
 
vector<int> graph[N];
vector<iii> input;
vector<ii> resp;
vector<ii> query;
 
int pai[N],lv[N];
int n,m,q;
int a,b,c;
 
ll ans = 0,K;
ll qnt[N];
 
int find(int x)
{
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}
 
void join(int x,int y)
{
	x = find(x);
	y = find(y);
 
	if(x == y) return;
 
	ans+=qnt[x]*qnt[y];
 
	if(lv[x] < lv[y]) pai[x] = y , qnt[y]+=qnt[x];
	else if(lv[x] > lv[y]) pai[y] = x , qnt[x]+=qnt[y];
	else
	{
		pai[x] = y;
		lv[y]++;
		qnt[y]+=qnt[x];
	}
 
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		qnt[i] = lv[i] = 1,pai[i] = i;
 
	for(int i=1;i<n;++i)
	{
		cin>>a>>b>>c;
		input.pb(mp(c,mp(a,b)));
	}
 
	sort(input.begin(),input.end());
	int idx = 0;
 
	for(int z=1;z<=q;++z)
	{
		cin>>K;
		query.pb(mp(K,z));
	}
 
	sort(query.begin(),query.end());
 
	for(int z=0;z<query.size();++z)
	{
		K = query[z].f;
 
		while(idx < input.size() && K >= input[idx].f)
		{
			int u = input[idx].s.f;
			int v = input[idx].s.s;
			if(find(u) != find(v))
				join(u,v);
			idx++;
		}
 
		resp.pb(mp(query[z].s,ans));
	}
 
	sort(resp.begin(),resp.end());
 
	for(int i=0;i<resp.size();++i)
		cout<<resp[i].s<<" ";
	cout<<"\n";
}