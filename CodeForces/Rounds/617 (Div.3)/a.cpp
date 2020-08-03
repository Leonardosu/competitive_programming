#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 2010 ;
const int INF = 1e9 + 7;

typedef pair<int,int> ii;
typedef long long int ll;

int v[N];
int t,n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n;
		ll sum = 0;
		int aux = -1;
		set<int> impar;

		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			sum+=v[i];
			if(v[i]%2 == 1)
				impar.insert(v[i]);
		}
		if(sum%2 == 1) cout<<"YES\n";
		else
		{
			bool ok = false;
			for(int i=0;i<n;++i)
			{
				if(v[i]%2 == 0 && impar.size()) 
				{
					ok = true;
					break;
				}
			}
			if(ok) cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
}