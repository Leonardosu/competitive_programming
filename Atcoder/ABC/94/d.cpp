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
	int n;
	cin>>n;
	vi v(n);
	for(int &x : v)
		cin>>x;
	if(n == 2)
	{
		cout<<*max_element(ALL(v))<<" "<<*min_element(ALL(v))<<"\n";
		return 0;
	}

	sort(ALL(v));
	int a = v.back();
	int div = (a+1)/2;

	int b = 0,dif = a;
	for(int i=0;i<n-1;++i)
	{
		if(abs(v[i]-div) < dif)
			dif = abs(v[i]-div), b = v[i];
	}
	// int b = v[n/2], c = v[(n+1)/2];
	
	// if(abs(b-div) < abs(c-div))
	cout<<a<<" "<<b<<"\n";
	
}