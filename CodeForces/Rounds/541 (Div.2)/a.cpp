#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	

	ll h1,h2,w1,w2;
	ll ans = 0;
	cin>>w1>>h1>>w2>>h2;

	ans += h2 + h1 + 2 + w1 + w2 + 2;
	ans += h1 + h2;
	
	ans += (w1 - w2);
	cout<<ans<<"\n";
}