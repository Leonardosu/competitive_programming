#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define e (no<<1)
#define d (no<<1) + 1
#define mid (ini+fim)/2
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		vi v;
		int n,k;
		cin>>n>>k;
		int ans = 0;
		for(int i=0;i<n;++i)
		{
			int a;
			cin>>a;
			if(a >= k)
				ans++;
			else
				v.pb(-a);
		}

		sort(all(v));
		int m = v.size();
		int cnt = 1;

		for(int i=1;i<m;++i)
		{
			if((-v[i])*(cnt + 1) >= k)
				ans++,cnt = 0;
			else
				cnt++;
		}

		cout<<ans<<"\n";
	}
}