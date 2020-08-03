#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;

ll gcd(ll a,ll b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	int t;
	cin>>t;
	while(t--)
	{
		int l = 1e9;
		int a,b;
		cin>>a>>b;
		l = min({max(a+a,b),max(b+b,a),max(a+b,b),max(a+b,a)});
		cout<<l*l<<"\n";
	}
}