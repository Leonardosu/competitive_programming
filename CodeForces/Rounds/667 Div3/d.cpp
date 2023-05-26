#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve_task() {
	string s;
	int k;
	cin>>s>>k;

	int n = sz(s);
	reverse(all(s));
	s.pb('0');
	
	ll sum = 0;
	for(char c : s)
		sum += (c-'0');
	if(sum <= k) {
		cout<<"0\n";
		return;
	}

	ll ans = 0;
	ll base = 1;
	for(int i=0;i<n;++i, base *= 10) {
		if(s[i] == '0') continue;
		int x = s[i] - '0';
		int pratirar = 10 - x;

		sum -= x;

		sum++;
		ans += base * pratirar;

		int j = i+1;
		s[i] = '0';
		s[j]++;

		while(j < n && s[j] > '9') {
			s[j] = '0';
			sum -= 9;

			s[j+1]++;
			j++;
		}

		if(sum <= k) {
			break;
		}
	}

	cout<<ans<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();

    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}