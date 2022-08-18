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

	string s;
	cin>>s;

	array<int, 4> v;
	for(int i=0;i<4;++i){
		v[i] = s[i] - '0';
	}

	int target = 7;

	for(int bit=0;bit<(1<<3);++bit) {
		int sum = v[0];
		string ans = to_string(v[0]);
		for(int i=0;i<3;++i) {
			if(bit&(1<<i)){
				sum += v[i+1];
				ans += '+';
			}
			else {
				sum -= v[i+1];
				ans += '-';
			}
			ans += to_string(v[i+1]);
		}

		if(sum == target) {
			ans += "=7";
			cout<<ans<<"\n";
			return 0;
		}
	}
}