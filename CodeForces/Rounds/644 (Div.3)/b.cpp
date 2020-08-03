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

int n,t;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.resize(n);
		for(int i=0;i<n;++i)
			cin>>v[i];
		
		sort(all(v));

		int best = 1e9;
		for(int i=1;i<n;++i) // seguidos
			best = min(best,v[i] - v[i-1]);
		
		cout<<best<<"\n";		

	}
}