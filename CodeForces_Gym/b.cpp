#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
 
int n,q;
int a,b;

vector<ii> matrizes;
map<int,int> X,Y;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>q;
	while(q--)
	{
 		X.clear(); Y.clear();
 		matrizes.clear();

		ll ans = 0;
 
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			matrizes.pb(mp(a,b));
			X[a]++;
			Y[b]++;
		}
 
		for(int i=0;i<n;++i)
		{
			//olho i -> j
			int x = matrizes[i].f,y = matrizes[i].s;
			ans+=X[y];
			//olho j -> i
			ans+=Y[x];			
			if(x == y) ans-=2;
		}
		cout<<ans/2<<"\n";
	}

}