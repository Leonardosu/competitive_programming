#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5 + 7;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

deque<int> ss;
vector<int> ans,v;
vector<ii> loop,before;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n,q;
	cin>>n>>q;
	v.resize(n);
	int pos = 0,best = -1;

	for(int i=0;i<n;++i)
	{
		cin>>v[i];
		ss.pb(v[i]);
		if(v[i] > best)
			best = v[i],pos = i;
	}

	int moves = 0,need = pos;

	for(int i=0;i<pos;++i)
	{
		int a = ss[0],b = ss[1];
		ss.pop_front();
		ss.pop_front();
				
		if(a > b)
		{
			ss.push_front(a);
			ss.pb(b);
		}
		else
		{
			ss.push_front(b);
			ss.pb(a);
		}
		before.pb({a,b});
	}

	int a = ss[0];
	ss.pop_front();

	for(int i=0;i<n-1;++i)
	{
		int b = ss[0];
		loop.pb({a,b});
		ss.pop_front();
		ss.pb(b);
	}

	ll l = before.size(),r = loop.size();
	for(int i=0;i<q;++i)
	{
		ll x;
		cin>>x;
		x--;
		if(x < l)
			cout<<before[x].f<<" "<<before[x].s<<"\n";
		else
		{
			cout<<loop[ (x-l)%r ].f<<" "<<loop[ (x-l)%r ].s<<"\n";
		}
	}
}