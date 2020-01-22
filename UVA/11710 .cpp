#include <bits/stdc++.h>	// O(N*Log)
#define f first				// Kruskal
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 5010;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<iii> v;
map<string,int> id;

int a,b,c;
int pai[N],lv[N];
int n,m,sum;
string name;

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
	if(lv[x] < lv[y]) pai[x] = y;
	else if(lv[x] > lv[y]) pai[y] = x;
	else
	{
		pai[x] = y;
		lv[y]++;
	}
}


int main()
{

	while(cin>>n>>m && (n+m))
	{
		id.clear(); v.clear();
		for(int i=1;i<=n;++i)
		{
			cin>>name;

			id[name] = i;
			pai[i] = i;
			lv[i] = 0;
		}
		string A,B;
		for(int i=1;i<=m;++i)
		{
			cin>>A>>B>>c;
			a = id[A];
			b = id[B];
			v.pb(mp(c,mp(a,b)));
		}

		sort(all(v));
		long long int sum = 0;
		int graph = 0,qnt = 0;
		cin>>name;

		for(int i=0;i<v.size();++i)
		{
			a = v[i].s.f, b = v[i].s.s;
			if(find(a) != find(b))
			{
				join(a,b);
				sum += v[i].f;
				qnt++;
			}
			if(qnt == n-1) break;
		}

		for(int i=1;i<=n;++i)
			if(pai[i] == i)
				graph++;
		if(graph == 1)	cout<<sum<<"\n";
		else cout<<"Impossible\n";
	}

}