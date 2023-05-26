#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;
typedef pair<int,int> ii;
typedef long long int ll;
inline ll gcd(ll a,ll b){	while(b){	a%=b;	swap(a,b);	}	return a;	}


vector<ii> v;
int l,r;
int n,k;
int ans = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int casos;

	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>l>>r;
		v.pb({l,r});
	}
	cin>>k;
	for(int i=0;i<n;++i)
	{
		l = v[i].f;
		r = v[i].s;

		if(k<=r)
			ans++;
	}


	cout<<ans<<"\n";
}