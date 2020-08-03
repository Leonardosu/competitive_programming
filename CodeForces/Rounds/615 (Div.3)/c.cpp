#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
 
const int N = 1;
const int INF = 1e9;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;

int t;
ll n,a,b,c;
vector<int> ans;
bool achou;
 
void go(ll x)
{
	for(ll i = x;i*i<=n;++i)
	{
		if(n%i == 0)
		{
			ans.pb(i);
			n/=i;
			achou = true;
			return;
		}
	}
	achou = false;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans.clear();
		achou = false;
 
		go(2);
		if(achou) go(ans[0]+1);
		if(achou)
		{
			if(n!= ans[1])
				ans.pb(n);
		}
		
		if(ans.size() == 3)
		{
			cout<<"YES\n";
			cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
		}
		else
			cout<<"NO\n";
 
	}
 
}