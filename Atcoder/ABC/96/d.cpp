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

bool isPrime(int x)
{
	if(x == 2) return true;
	for(int i=2;i*i<=x;++i)
		if(x%i == 0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,i = 0;
	cin>>n;
	
	for(int i=11;i<=55555 && n;++i)
		if(isPrime(i) && i%5 == 1)
		{
			cout<<i<<" ";
			n--;
		}

	cout<<"\n";
}