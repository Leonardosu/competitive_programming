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
	cin>>s;

	auto exist = [&](int len) {
		bool flag = false;
		int a = 0, b = 0, c = 0;
		auto process = [&](char ch, int op) {
			if(ch == '1') a+=op;
			else if (ch == '2') b+=op;
			else c+=op;
		};

		for(int i=0;i<len;++i) {
			process(s[i], 1);
		}

		if(a>0 && b>0 && c>0) flag = true;
		int ini = 0;
		for(int i=len;i<sz(s);++i) {
			process(s[ini++],-1);
			process(s[i], 1);
			if(a>0 && b>0 && c>0) flag = true;
		}

		return flag;
	};


	int l = 3, r = sz(s);	
	int ans = 0;
	while(l<=r){
		int mid = (l+r)/2;
		if(exist(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
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