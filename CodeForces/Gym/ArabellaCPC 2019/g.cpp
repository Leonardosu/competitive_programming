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

const int N = 1e6 + 7;
double f[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n = 8;
	cin>>n;
	f[0] = 0;
	/*
		1 2 3 
		1 3 2 
		2 1 3 
		2 3 1 
		3 1 2 
		3 2 1 
		vi v = {1,2,3};
		do {
			for(auto x : v)
				cout<<x<<" ";
			cout<<"\n";
		} while(next_permutation(ALL(v)));
	*/

	for(int i=1;i<=n;++i) {

		double a = (i-1);
		// double a = (i-1) * (i-1)/2
		// double b = (n-i) * (n-i-1)/2;
		// cout<<a<<" "<<b<<" = "<<a-b<<"\n";
		f[i] = f[i-1] + i * (a/n);
	}

	cout<<fixed<<setprecision(10);
	cout<<f[n]<<"\n";
}