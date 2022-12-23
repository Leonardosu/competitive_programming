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

int q,n,m,a[N],x;
int t[N],last;
ll ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i)
		{
			cin>>x;
			t[x] = i;
		}

		for(int i=1;i<=m;++i)
			cin>>a[i];

		last = 1;
		ans = 0;
		for(int i=1;i<=m;++i)
		{
			if(t[a[i]] > last)
			{
				last = t[a[i]];
				ans += (last - i)*2 + 1;
			}
			else
				ans++;
		}
		cout<<ans<<"\n";
	}
}