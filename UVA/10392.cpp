#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;

void solve_task()
{
	string s = "    ";
	string ans = "";
	
	while(n % 2 == 0)
	{
		n>>=1;
		ans += s + to_string(2) + "\n";
	}

	for(ll i=3;i*i<=n;++i)
	{
		while(n % i == 0)
		{
			n/=i;
			ans += s + to_string(i) + "\n";
		}
	}

	if(n > 1)
		ans += s + to_string(n) + "\n";

	cout<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while(cin>>n && n > 0)
		solve_task();
}

