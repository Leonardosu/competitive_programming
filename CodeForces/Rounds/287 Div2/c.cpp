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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll h, k;

    cin>>h>>k;

    ll visited = 0;
    int dir = 0;

    while(h--)
    {
    	ll q = (k-1)>>h;
    	// cout<<q<<" ~~\n";
    	if( (q&1LL) != dir)
    		visited += 1LL<<(h+1LL);
    	else
    	{
    		dir = (1+dir)%2;
    		visited++;
    	}
    }

    cout<<visited<<"\n";
}