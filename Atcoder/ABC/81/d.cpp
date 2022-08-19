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


bool valid(vector<int> &v) {
	int n = v.size();
	for(int i=1;i<n;++i)
		if(v[i-1] > v[i])
			return false;
	return true;
}

vector<pii> positiveSolve(vector<int> &v) {
	vector<pii> moves;
	for(int i=1;i<(int)v.size();++i){
		moves.pb({i-1, i});
		v[i] += v[i-1];
	}
	assert(valid(v));
	return moves;
}

vector<pii> negativeSolve(vector<int> &v) {
	vector<pii> moves;
	for(int i=v.size()-2;i>=0;--i){
		moves.pb({i+1, i});
		v[i] += v[i+1];
	}
	assert(valid(v));
	return moves;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	vi v(n);

	bool positive = true, negative = true, zero = true;
	pii small = {INT_MAX,0}, big = {INT_MIN, 0};
	int i = 0;
	for(int &x : v) {
		cin>>x;

		if(x < 0) positive = false;
		else if(x > 0) negative = false;

		zero &= (x == 0);
		if(x < small.f)
			small = {x, i};
		if(x > big.f)
			big = {x, i};
		i++;
	}

	vector<pii> adjust;

	if(zero || valid(v)) {
		cout<<"0\n";
		return 0;
	} else if(!positive && !negative){
		int toAdd = 0, idx = 0;
		if(abs(big.f) >= abs(small.f)) {
			positive = true;
			toAdd = big.f;
			idx = big.s;
		} else {
			negative = true;
			toAdd = small.f;
			idx = small.s;
		}

		i = 0;
		for(int &x : v) {
			x += toAdd;
			adjust.pb({idx, i++});
		}
	}

	vector<pii> ans = (positive ? positiveSolve(v) : negativeSolve(v));
	cout<<adjust.size() + ans.size()<<"\n";
	for(auto &[x, y] : adjust)
		cout<<x+1<<" "<<y+1<<"\n";
	for(auto &[x, y] : ans)
		cout<<x+1<<" "<<y+1<<"\n";
}