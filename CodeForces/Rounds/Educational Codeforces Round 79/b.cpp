#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end();
using namespace std;

const int N = 100010;
const int INF = 1e9;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;

ll s,n,x,t,soma;
ll v[N],maior,total;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		total = 0;


		for(int i=1;i<=n;++i)
		{
			cin>>v[i];
			total += v[i];
		}
		
		int id = 1;
		maior = v[1];
		soma = 0;
		id = 1;

		for(int i=2;i<=n;++i)
		{
			soma+=v[i];
			if(v[i] > maior)
			{
				soma+=maior;
				soma-=v[i];
				maior = v[i];
				if(soma > s) break;
				id = i;
			}
			if(soma > s) break;
		}

		if(total <= s) id = 0;
		cout<<id<<"\n";
	}
}