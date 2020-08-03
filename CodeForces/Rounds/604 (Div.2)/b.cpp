#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define debug(x) cout<<"\n### _("<<x<<")_###\n";
using namespace std;

const int N = 200010;
const int INF = 1e9;
typedef long long int ll;
typedef pair<int,int> ii;


int n,t,cnt;
int v[N],pos[N];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>v[i];
			pos[v[i]] = i;
 		}

		cnt = 1;
		int l = pos[1], r = pos[1];

		cout<<1;
		for(int i=2;i<=n;++i)
		{
			int x = pos[i];
			l = min(x,l);
			r = max(x,r);
			cnt++;
			if(r-l+1== cnt)
				cout<<1;
			else
				cout<<0;
		}
		cout<<"\n";
	}
}