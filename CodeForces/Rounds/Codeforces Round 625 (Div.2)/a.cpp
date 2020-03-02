#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
const int N = 210;
const int INF = 1e9;
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int n,igual;
int a[N],b[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	int x = 0, y = 0;

	for(int i=0;i<n;++i)
	{
		int z;
		cin>>z;
		if(z)
		{
			a[i] = true;
			x++;
		}

	}

	for(int i=0;i<n;++i)
	{
		int z;
		cin>>z;
		if(z)
		{
			y++;
			b[i] = true;
		}
	}

	for(int i=0;i<n;++i)
		if(a[i] && b[i])
		{
			igual ++;
			x--;
			y--;
		}

	if(x == 0) cout<<"-1\n";
	else
	{
		int ans = (y)/x;
		cout<<ans + 1<<"\n";
	}

}