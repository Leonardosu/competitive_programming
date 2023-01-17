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


    ll a, b, c, d;
    cin>>a>>b>>c>>d;

    // (a + b.k) <= k.c.d
    //a <= k(c.d - b)
    if(c*d - b <= 0) cout<<"-1\n";
    else {
    	ll up = (a + c*d - b - 1);
    	ll down = c*d - b;
    	cout<<up/down<<"\n";
    }
}