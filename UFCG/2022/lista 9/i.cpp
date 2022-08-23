#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;

#define int long long
const int inf = 1e18;
int n;
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23};

int solve(int num, int i, int val) {
	if(i == -1) 
		return num == 1 ? val : inf;
	
	int sal = inf/val;
	int qnt = 1, tmp = 1;
	int res = solve(num, i - 1, val);
	while(prime[i] <= sal) {
		tmp *= prime[i],
		sal /= prime[i];
		qnt++;
		if(num % qnt == 0)
			res = min(res, solve(num/qnt, i - 1, 1LL*val*tmp));
	}
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	if(n == 1) {
		cout<<"1\n";
	} else {
		cout<<solve(n, 1LL*prime.size() - 1, 1)<<"\n";
	}

	return 0;
}