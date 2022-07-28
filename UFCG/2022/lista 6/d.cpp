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

	int n, k;
	cin>>n>>k;

	ll big = 0;
	vector<int> ans[n];

	int currOdd = 1, currEven = 2;
	for(int i=0;i<n;++i) {
		ans[i].resize(4);

		for(int j=0;j<3;++j) {
			ans[i][j] = k*currOdd;
			currOdd += 2;
		}


		ans[i].back() = k*currEven;
		currEven += 6;
	}

	currOdd-=2, currEven -= 6;
	cout<<max(currOdd, currEven) * k<<"\n";
	for(int i=0;i<n;++i){
		for(int j=0;j<4;++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
		// 2 ^ 4
		//check
		// for(int bitmask=0;bitmask<(1<<4);++bitmask) {
		// 	int qwe = 0;
		// 	int qnt = 0;
		// 	for(int j=0;j<4;++j)
		// 		if(bitmask & (1<<j)) {
		// 			qnt++;
		// 			qwe = gcd(qwe, ans[i][j]);
		// 		}

		// 	if(qnt == 2 && qwe != k) {
		// 		cout<<i<<" deu ruim com "<<bitmask<<"->"<<qwe<<"\n";
		// 	}
		// }
		
	}
}