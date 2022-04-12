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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a,b,c,k;
	cin>>a>>b>>c>>k;
	ll x = max({a,b,c});
	ll sum = a + b + c - x;
	sum += x*(1<<k);
	cout<<sum<<"\n";
}