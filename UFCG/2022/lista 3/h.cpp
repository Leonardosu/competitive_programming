#include "bits/stdc++.h" //Maximal GCD
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

ll n, k, best;
const int MAX = 1e6;
void go(ll g)
{
	ll pa = 1LL * g * k * (k-1LL)/2LL;
	ll resto = n - pa;
	if(resto%g != 0) return;
	if(resto > 1LL * (k-1LL) * g)
		best = max(best, g);
}

void printAns(){
	ll curr = n;
	for(ll i=1;i<=k-1;++i)
	{
		curr -= i*best;
		cout<<i*best<<" ";
	}
	cout<<curr<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    if(k > MAX)
    	cout<<"-1\n";
    else
    {
    	best = -1;
    	for(ll i=1;i*i<=n;++i)
    		if(n%i == 0)
    		{
    			go(i);
    			go(n/i);
    		}

    	if(best != -1)
    		printAns();
    	else
    		cout<<"-1\n";
    }
}