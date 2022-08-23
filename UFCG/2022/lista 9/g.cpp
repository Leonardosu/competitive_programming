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

map<string, string> existSub;
set<string> vis;
vector<string> ansMoves;
const int N = 1e3 + 7;
int ans[N];

string genMove(int l, int r, int id) {
	return to_string(l) + " " + to_string(r) + " " + to_string(id);
}

void genSubstrings(string &s, int id) {
	if(present(vis, s)) return;
	vis.insert(s);

	for(int i=1;i<(int)s.size();++i) {
		string twoDigit = s.substr(i-1, 2);
		existSub[twoDigit] = genMove(i, i+1, id);

		if(i >= 2) {
			string threeDigit = s.substr(i-2, 3);
			existSub[threeDigit] = genMove(i-1, i+1, id);
		}
	}

}


bool canBuild(string &s, int i, vector<string> &moves) {
	int n = s.size();
	if(i >= n) {
		ansMoves = moves;
		return true;
	}

	if(ans[i] != -1)
		return ans[i];

	
	bool can = false;
	for(int j=1;j<=2 && i+j<n;++j) {
		string toAdd = s.substr(i, j+1);
		if(existSub.count(toAdd)) {
			moves.pb(existSub[toAdd]);
			can |= canBuild(s, i+j+1, moves);
			moves.pop_back();
		}
	}

	ans[i] = can;
	return can;
}

void solve_task()
{
	int n, m;
	cin>>n>>m;

	memset(ans, -1, sizeof ans);
	existSub.clear(); vis.clear();
	for(int i=1;i<=n;++i) {
		string s;
		cin>>s;
		genSubstrings(s, i);
	}


	vector<string> moves;
	string target;
	cin>>target;
	
	if(canBuild(target, 0, moves)) {
		cout<<ansMoves.size()<<"\n";
		for(string &move : ansMoves)
			cout<<move<<"\n";
	} else {
		cout<<"-1\n";
	}

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	while(T_T--)
		solve_task();
}