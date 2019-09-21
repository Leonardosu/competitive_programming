#include <bits/stdc++.h> // UVA 10810 - Ultra-QuickSort
#define N 500100 			// Solution with BIT/Compress input
#define all(x) x.begin(),x.end()
using namespace std;

typedef long long int ll;

int n;
ll BIT[N],x;

void upd(int id,int x)
{
	while(id < N)
	{
		BIT[id]+=x;
		id += id&-id;
	}
}

ll query(int id)
{
	ll sum = 0;
	while(id > 0)
	{
		sum+=BIT[id];
		id -= id&-id;
	}
	return sum;
}

map<ll,int> compress;
vector<ll> input,aux;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n && n)
	{
		for(int i=0;i<N;++i) BIT[i] = 0;

		ll ans = 0; 
		compress.clear(); input.clear(); aux.clear();

		for(int i=0;i<n;++i)
		{
			cin>>x;
			input.push_back(x);
			aux.push_back(x);
		}

		sort(all(aux));
		for(int i=0;i<aux.size();++i)
		{
			ll now = aux[i];
			compress[now] = i+1;
		}

		for(int i=0;i<input.size();++i)
		{
			ll now = compress[input[i]];
			ans+=query(n) - query(now-1);
			upd(now,1);
		}

		cout<<ans<<"\n";
	}
}