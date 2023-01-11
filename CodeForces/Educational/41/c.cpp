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

const int N = 200 + 7;
int grid[N][N];
typedef vector<string> T;

vector<vector<string>> pieces;
void build(T &state, pii &pos) {
	int n = state.size();
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			grid[pos.f + i][pos.s + j] = state[i][j] - '0';
}


void build(string &states, int n) {
	int k = 0;
	vector<pii> auxx = {{0,0}, {0,n}, {n, 0}, {n, n}};
	for(char &c : states) {
		build(pieces[c-'0'], auxx[k++]);
	}	
}

int minToSolve(string &states, int n) {
	build(states, n);

	int a = 0;
	for(int i=0;i<2*n;++i)
		for(int j=0;j<2*n;++j) {
			if((i+j)%2 != grid[i][j]) 
				a++;
		}
	return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<4;++i) {
    	vector<string> piece(n);
    	for(int j=0;j<n;++j) {
    		cin>>piece[j];
    	}
    	pieces.pb(piece);
    }

    string state = "0123";
    int ans = INT_MAX;
    do {
    	ans = min(ans, minToSolve(state, n));
    } while(next_permutation(ALL(state)));

    cout<<ans<<"\n";
}