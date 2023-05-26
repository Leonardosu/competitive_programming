#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end();
using namespace std;
const int N = 1e5;
const int INF = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

int t;
ll a,b,ans;
ll n,m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b;
		
		ans = (a-1)*(b-1);
		ans = max({n*(b),m*(a),n*(m - b - 1LL),m*(n - a - 1LL)});
		
		cout<<ans<<"\n";
	}	
}