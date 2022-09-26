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

	ll n,k;
	cin>>n>>k;

	if(2LL*k >= n)
		cout<<"10\n";
	else {
		ll rounds = n/k;
		int sobra = n%k;
		if(sobra)
			rounds++;

		cout<<5LL*rounds<<"\n";
	}
}