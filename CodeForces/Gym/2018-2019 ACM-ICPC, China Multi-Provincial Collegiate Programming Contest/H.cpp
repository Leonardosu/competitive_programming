#include <bits/stdc++.h> //Greedy
#define f first
#define s second 
#define pb push_back
#define mp make_pair
#define N 100010

using namespace std;
typedef long long int ll;

struct tipo
{
	int atk;
	int Hp;
	int need;

};

int t,n;
tipo Monster[N];
ll soma,ans;

bool comp(tipo A,tipo B)
{
	return A.atk*B.need > B.atk*A.need;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>t;
	for(int z=1;z<=t;++z)
	{
		cin>>n;	

		soma = ans = 0;

		for(int i=1;i<=n;++i)
		{
			cin>>Monster[i].Hp>>Monster[i].atk;

			Monster[i].need = ( -1 + sqrt(1 + 8*Monster[i].Hp) + 2 - 1)/2;
			int x = Monster[i].need;
			while((x*(x+1))/2 < Monster[i].Hp)
				x++;
			Monster[i].need = x;
			soma+=Monster[i].atk;
		}

		sort(Monster + 1,Monster + n + 1, comp);

		for(int i=1;i<=n;++i)
		{
			ans+=soma*Monster[i].need;
			soma-=Monster[i].atk;
		}

		cout<<"Case #"<<z<<": "<<ans<<"\n";
	}
}