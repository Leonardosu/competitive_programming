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
	ll a,b;
	cin>>a>>b;
	if(a + b == 2) 
		cout<<"1\n";
	else if(a == 1 || b == 1)
		cout<<max(a,b) - 2<<"\n";
	else
	{
		cout<<(a-2LL)*(b-2LL)<<"\n";
	}
}