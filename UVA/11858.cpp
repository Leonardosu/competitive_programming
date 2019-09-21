#include <bits/stdc++.h> // UVA 11858 - Frosh Week
#define N 1000100 			// Solution with BIT/compress data
using namespace std;

typedef long long int ll;

int n,x;
ll ans,BIT[N];
map<ll,int> compress;
vector<ll> input,aux;

void upd(int id,int x)
{
	while(id<N)
	{
		BIT[id]+=x;
		id+=(id&-id);
	}
}

int query(int id)
{
	int soma = 0;
	while(id>0)	
	{
		soma+=BIT[id];
		id-=(id&-id);
	}
	return soma;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n)
	{
		for(int i=0;i<=n;++i) BIT[i] = 0;
		ans = 0; compress.clear(); input.clear(); aux.clear();

		for(int i=0;i<n;++i)
		{
			cin>>x;
			aux.push_back(x);
			input.push_back(x);
		}


		sort(aux.begin(),aux.end());
		for(int i=0;i<n;++i)
		{
			x = aux[i];
			compress[x] = i+1;
		}

		for(int i=0;i<n;++i)
		{
			x = input[i]; 
			x = compress[x];
			ans+=query(n) - query(x);
			upd(x,1);
		}

		cout<<ans<<"\n";
	}
}