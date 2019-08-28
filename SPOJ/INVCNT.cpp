#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define MAXN 200010
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int BIT[MAXN];
int n,q,a;

ll query(int i)
{
	ll A=0;
	while(i>0)
	{
		A+=BIT[i];
		i-=i&-i;
	}
	return A;
}

void update(int i,int x)
{
	while(i<MAXN)
	{
		BIT[i]+=x;
		i+=i&-i;
	}
}

vector<int> aux,input;
map<int,int> transf;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>q;
	while(q--)
	{
		cin>>n;

		ll ans = 0; input.clear(); transf.clear(); aux.clear(); // reset
		memset(BIT,0,sizeof(BIT));

		for(int i=1;i<=n;++i)
		{
			cin>>a;
			input.push_back(a);
			aux.push_back(a);
		}

		sort(input.begin(),input.end());

		int count = 0;

		for(int i=0;i<input.size();++i)
		{
			int x = input[i];
			if(!transf[x])
				count++;
			transf[x] = count;
		}

		for(int i=0;i<aux.size();++i)
		{
			a = aux[i];
			a = transf[a];
			// cout<<"#"<<a<<" "<<transf[a]<<" \n";
			ans += query(count) - query(a);
			update(a,1);
		}

		cout<<ans<<"\n";
	}
}