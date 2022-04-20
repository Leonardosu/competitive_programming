#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int N = 1e5 + 700;
bool can[N];

void markPrimes(int n)
{ 
	vi primos;

    for(int i = 2; i*i <= n; ++i)
    	while(n % i == 0)
    	{
    		n/= i;
    		primos.pb(i);
    	}
    
    if (n > 1)
    	primos.pb(n);

    for(int &p : primos)
    	if(can[p])
    		for(int k=p;k<N;k += p)
    			can[k] = false;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TT = 1;
	// cin>>TT;
	
	while(TT--)
	{
		int n,m;
		cin>>n>>m;

		for(int i=0;i<N;++i)
			can[i] = true;


		vi v(n);
		for(int &x : v)
		{
			cin>>x;
			markPrimes(x);
		}
	
		vi ans;
		can[1] = true;
		for(ll i=1LL;i<=m;++i)
			if(can[i])
				ans.pb(i);		

		cout<<sz(ans)<<"\n";
		for(int &x : ans)
			cout<<x<<"\n";
	}
}