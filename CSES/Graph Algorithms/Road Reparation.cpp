#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 100010;
const int INF = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,m;
int pai[N],lv[N];
vector<iii> e;

int find(int x)
{
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return ;
	if(lv[x] > lv[y]) swap(x,y);
	if(lv[x] == lv[y]) lv[y]++;	
	pai[x] = y;	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		pai[i] = i,lv[i] = 0;
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		e.pb({c,{a,b}});
	}

	sort(e.begin(),e.end());
	ll cost = 0;
	for(int i=0;i<m;++i)
	{
		int a = e[i].s.f,b = e[i].s.s;
		if(find(a) != find(b))
		{
			join(a,b);
			cost+=e[i].f;
		}
	}

	int way = 0;
	for(int i=1;i<=n;++i)
		if(pai[i] == i) way++;

	if(way > 1) cout<<"IMPOSSIBLE\n";
	else cout<<cost<<"\n";
}