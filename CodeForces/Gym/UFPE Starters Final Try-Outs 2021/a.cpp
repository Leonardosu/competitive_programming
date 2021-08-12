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

ll phi(ll n) 
{
    ll result = n;
 
    for (ll i = 2LL; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    ll n,x;
    cin>>n;
    
    if(n&1)
        n--;
    cout<<phi(n+2)<<"\n";
}