#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 100010

using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;


ll ope(ll x)
{
	ll ans = 0;
	while(x>1)
	{
		if(x == 1)
			break;

		if(x == 2)
		{
			ans++;
			break;
		}

		if(x%2 == 0)
			x/=2;
		else
			x-=1;
		ans++;
	}
	return ans;
}


ll x;
ll prefix[N],v[N];

int t,n,q;
int l,r;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		for(int i=0;i<=n;++i)
			prefix[i] = 0;

		for(int i=1;i<=n;++i)
		{
			cin>>x;
			prefix[i] = prefix[i-1] + ope(x);
			// cout<<x<<"need :"<<ope(x)<<" #\n";			
		}
		for(int i=0;i<q;++i)
		{
			cin>>l>>r;
			cout<<prefix[r]-prefix[l-1]<<"\n";
		}
	}

}