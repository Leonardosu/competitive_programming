#include <bits/stdc++.h> //DSU
#define f first			//Leonardo Su 
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 200010;
typedef long long int ll;

typedef pair<int,int> ii;
typedef pair<ll,ii> iii;

bool milk[N];

ll pai[N],lv[N];
ll a,b,c,qnt;
ll t,n,m;

ll ans = 0;
vector<iii> input;

int find(int x)
{
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x,int y,int cost)
{
	x = find(x);
	y = find(y);

	if(x == y) return;
	if(milk[x] && milk[y]) return;


	if(lv[x] < lv[y]) pai[x] = y;
	else if(lv[x] > lv[y]) pai[y] = x;
	else
	{
		pai[y] = x;
		lv[x]++;
	}

	if(milk[x] || milk[y])
	{
		x = find(x);
		y = find(y);
		milk[x] = true;
		milk[y] = true;
	}

	ans += cost;
}

void reset()
{
	for(int i=1;i<=n;++i)
	{
		pai[i] = i;		lv[i] = 0;		milk[i] = false;
	}

	input.clear();
	ans = 0;	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		reset();

		int x;

		for(int i=1;i<=n;++i)
		{
			cin>>x;
			if(x)
				milk[i] = true;
			else
				milk[i] = false;			
		}
		
		for(int i=1;i<=m;++i)
		{
			cin>>a>>b>>c;
			input.pb(mp(c,mp(a,b)));
		}

		sort(all(input));

		for(int i=0;i<input.size();++i) //Union 
		{
			int u = input[i].s.f;
			int v = input[i].s.s;
			if(find(u) != find(v))
				join(u,v,input[i].f);			
		}

		//Check
		int possible = 1;
		for(int i=1;i<=n;++i)
			possible*=milk[find(i)];

		if(possible)
			cout<<ans<<"\n";
		else
			cout<<"impossible\n";
	}
}
