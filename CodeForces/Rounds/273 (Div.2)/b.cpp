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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin>>n>>m;

    ll qnt = n/m;
    ll resto = n%m;    
    ll mn = qnt * (qnt - 1) * m + qnt * resto * 2;

    resto = n - m + 1;
    ll mx = resto * (resto - 1);
    cout<<mn/2LL<<" "<<mx/2LL<<"\n";
}