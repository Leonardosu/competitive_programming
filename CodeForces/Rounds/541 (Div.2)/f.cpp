#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 150100;

queue<int> g[maxn];
int n,pai[maxn],lv[maxn],cnt[maxn];

int find(int x)
{
	if(pai[x] == x)return x;
	return pai[x] = find(pai[x]);
}

void join(int x,int y)
{
	x = find(x);
	y = find(y);

	if(x == y) return;

	if(lv[x] == lv[y]) lv[x]++;
	else if(lv[x] < lv[y]) swap(x,y);
	pai[y] = x;	
	// ****************
	cnt[x] += cnt[y];
	cnt[y] = 0;
	while(!g[y].empty())
	{
		g[x].push(g[y].front());
		g[y].pop();
	}
	// cnt[y] = cnt[x];
	// ****************
}



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>n;
	for(int i=1;i<=n;++i)
	{
		g[i].push(i);
		pai[i] = i;
		cnt[i] = 1;
	}

	for(int i=1;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		join(a,b);
	}
	
	int now = find(1);
	while(!g[now].empty())
	{
		cout<<g[now].front()<<" ";
		g[now].pop();
	}
	cout<<"\n";
}