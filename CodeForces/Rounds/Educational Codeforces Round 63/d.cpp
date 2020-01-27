#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define debug(x) cout<<"###debug###\n"<<x<<"\n";
using namespace std;

const int N = 300100;
const int INF = 1e9;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

ll v[N],prefix[N],suffix[N];
ll L[N],R[N],x;
ll ans,menor;
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>x;
	L[0] = 0LL;
	prefix[0] = 0LL;
	suffix[n+1] = 0LL;

	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		ans+=v[i];
		prefix[i] = v[i] + prefix[i-1];
	}

	for(int i=n;i>=1;--i)
		suffix[i] = suffix[i+1] + v[i];

	menor = 0LL;
	for(int i=1;i<=n;++i)
	{
		L[i] = max(0LL,prefix[i] - menor);
		menor = min(menor,prefix[i]);
	}

	menor = 0LL;
	for(int i=n;i>=1;--i)
	{
		R[i] = max(0LL,suffix[i] - menor);
		menor = min(menor,suffix[i]);
	}
	
	ans = 0LL;
	ll best = 0LL;
	for(int i=1;i<=n;++i)
	{
		best = max(best,L[i] - prefix[i]*x);
		ans = max(ans,best + R[i+1] + prefix[i]*x);
	}
	cout<<ans<<"\n";
}