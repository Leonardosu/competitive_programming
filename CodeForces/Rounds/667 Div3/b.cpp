#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,x,y,n;
		cin>>a>>b>>x>>y>>n;

		ll menos = min(a-x,n);
		ll best = (a-menos)*max(y,b-n+menos);

		menos = min(b-y,n);
	 	best = min(best,(b-menos)*max(x,a-n+menos));

		cout<<best<<"\n";
	}
	
}
