#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 300;
const int INF = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

int t;
int n;

int ans[N],v[N];
set<int> caras;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n;
		caras.clear();

		for(int i=1;i<=2*n;++i)
		{
			ans[i] = 0;
			caras.insert(i);
		}
		
		bool possible = true;
		for(int i=1;i<=n;++i)
		{
			int x;
			cin>>x;
			if(caras.find(x) == caras.end())
			{
				possible = false;
			}
			else				
			{
				ans[2*i] = x;
				caras.erase(x);
			}
			
		}

		int j;
		
		for(int i=1;i<=n;++i)
		{
			j = 2*i - 1;
			// ans[j]
			int x = ans[2*i];
			auto next = upper_bound(all(caras),x);

			if(next == caras.end())
			{
				possible = false;
				break;
			}
			
			ans[j] = *next;
			caras.erase(*next);

			if(ans[2*i] < ans[j]) swap(ans[2*i],ans[j]);
		}

		// if(caras.size() > 0) possible = false;

		if(!possible) cout<<"-1\n";
		else
		{
			for(int i=1;i<=2*n;++i)
				cout<<ans[i]<<" ";
			cout<<"\n";
		}
	}
}