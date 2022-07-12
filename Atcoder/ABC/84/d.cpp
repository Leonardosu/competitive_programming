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

bool isPrime(int x) {
	if(x < 2) return false;
	if(x == 2) return true;
	for(int i=2; i*i <= x; ++i)
		if(x%i == 0)
			return false;
	return true;	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int N = 1e5 + 7;
	int qnt[N]; memset(qnt, 0 ,sizeof qnt);

	for(int i=1;i<N;++i) {
		if(isPrime(i) && isPrime((i+1)/2)) {
			qnt[i]++;
		}
		qnt[i] += qnt[i-1];
	}

	int q;
	cin>>q;
	while(q--) {
		int l,r;
		cin>>l>>r;
		cout<<qnt[r] - qnt[l-1]<<"\n";
	}
}