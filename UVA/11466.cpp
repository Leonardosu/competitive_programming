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
	ll largest = -1;
	ll previous = n;
	ll primeqnt = 0;
	if(n < 0)
		n *= -1;
	
	for(ll i=2;i*i<=n;++i)
	{
		if(n%i == 0)
		{
			primeqnt++;
			largest = i;
			while(n % i == 0)
				n/=i;
		}
	}


	if(primeqnt == 1 && n == 1)
		largest = -1;
	else if(primeqnt == 0 && n > 1)
		largest = -1;
	else if(n > 1)
		largest = n;
	
	cout<<largest<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin>>n && n)
		solve_task();
}