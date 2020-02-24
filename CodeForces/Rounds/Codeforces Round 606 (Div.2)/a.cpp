#include <bits/stdc++.h>
#define f fist
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

typedef long long int ll;
typedef pair<int,int> ii;

vector<ll> save;
ll now;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for(int i=1;i<=9;++i)
	{
		now = 0;
		for(int j=0;j<9;++j)
		{
			now += i*poww(10,j);
			save.pb(now);
		}
	}	

	sort(all(save));
	save.pb(INF + 5);

	int t;
	cin>>t;
	while(t--)
	{
		cin>>now;
		for(int i=0;i<save.size();++i)
		{
			if(save[i] > now)
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
}	