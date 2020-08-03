#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end();
using namespace std;
const int N = 200010;

typedef long long int ll;
typedef pair<int,int> ii;

int n;
ll ans = 0LL;
vector<ii> v;

map<int,ll> soma;
map<int, vector<int> > caras;
set<int> val;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	v.resize(n);

	for(int i=0;i<n;++i)
	{
		cin>>v[i].f;
		val.insert(v[i].f);
	}

	for(int i=0;i<n;++i)
	{		
		cin>>v[i].s;
		soma[v[i].f] += v[i].s;
		caras[v[i].f].pb(v[i].s);
	}
	
	priority_queue<int> fila;

	ll ans = 0;
	ll now = 0;

	for(auto day : val)
	{
		for(auto x : caras[day])
			fila.push(x);
		
		
		now += soma[day];
		if( int(fila.size()) > 1)
		{
			now -= fila.top();		
			fila.pop();
			ans += now;
			val.insert(day + 1);
		}
		else
		{
			now -= fila.top();
			fila.pop();
		}

	}

	cout<<ans<<"\n";
}