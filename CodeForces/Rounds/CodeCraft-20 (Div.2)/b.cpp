#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
const int N = 2e5 + 7;
const int INF = 1e9;
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int t;
ll n,m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		vector<int> v;
		cin>>n>>m;
		v.resize(n);
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
		}
		ll resto = 0;
		for(int i=1;i<n;++i)
			resto += v[i];
		cout<<min(resto+v[0],m)<<"\n";
	}	
}