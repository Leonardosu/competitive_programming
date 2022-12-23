#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1;
const int INF = 1e9;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;

ll a,b,c,t;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<ll> v;
	cin>>t;
	while(t--)
	{
		v.clear();
		cin>>a>>b>>c;
		v.pb(a);
		v.pb(b);
		v.pb(c);
		sort(all(v));
		if(v[2] > v[1] + v[0] + 1) cout<<"No\n";
		else	cout<<"Yes\n";	
	}
}