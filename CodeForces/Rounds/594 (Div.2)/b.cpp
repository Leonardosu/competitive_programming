#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
 
const int N = 100010;
const int INF = 1e9;
 
typedef pair<int,int> ii;
typedef long long int ll;
 
vector<int> v;
int n,x;
ll ans = 0;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		v.pb(x);
	}
 
	sort(all(v));
 
	ll a = 0;
	ll b = 0;
	for(int i=0;i<n/2;++i)
		a+=v[i];
	for(int i=n/2;i<n;++i)
		b+=v[i];
	ans = a*a + b*b;
	cout<<ans<<"\n";
}