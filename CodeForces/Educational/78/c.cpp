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

int solve(vector<int> &a, vector<int> &b) {
	int n = sz(a);

	int left = 0, right = 0;
	for(int x : a) {
		left += (x == 1 ? 1 : -1);
	}

	map<int,int> pos; //blue = 1, red = 2
	pos[0] = 0;

	for(int i=0;i<n;++i) {
		right += (b[i] == 1 ? 1 : -1);
		if(!pos.count(right))
			pos[right] = i+1;
	}

	int total = left + right;
	int cur = 0;
	int ans = 2*n;
	for(int i=n-1;i>=0;--i) {
		cur += (a[i] == 1 ? 1 : -1);
		int target = total - cur;

		if(pos.count(target)) {
			ans = min(ans, n-i + pos[target]);
		}
	}

	return ans;
}

void solve_task() {
	int n;
	cin>>n;
	vi a(n), b(n);
	int total = 0;
	for(int &x : a) {
		cin>>x;
		total += (x == 1 ? 1 : -1);
	}
	for(int &x : b) {
		cin>>x;
		total += (x == 1 ? 1 : -1);
	}

	if(total == 0) {
		cout<<"0\n";
		return;
	}

	int ans = solve(a, b);
	reverse(all(a)); reverse(all(b));
	cout<<min(ans,solve(b, a))<<endl;
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