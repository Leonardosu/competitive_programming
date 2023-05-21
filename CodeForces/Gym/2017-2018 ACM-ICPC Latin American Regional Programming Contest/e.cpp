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

int mod;
const int N = 1e3 + 7;
int base[N];
string s;
int n, k;
int dp[N][N];
int helper[N][N];

int solve(int i, int resto) {
	if(i == n) {
		return resto == 0;
	}

	int &state = dp[i][resto];
	if(state != -1) return state;

	state = 0;

	if(s[i] == '?') {
		for(int di = !i;di<10;++di) {
			if(solve(i+1, (resto*10 + di)%mod)) {
				helper[i][resto] = di;
				state = true;
				break;
			}
		}
	} else {
		if(solve(i+1, (resto*10 + (s[i]-'0'))%mod)) {
			helper[i][resto] = s[i] - '0';
			state = true;
		}
	}

	return state;
}

void recupera(int i, int resto) {
	if(i == n) {
		cout<<endl;
		return;
	}

	cout<<helper[i][resto];
	recupera(i+1,(resto*10 + helper[i][resto])%mod);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();    
    memset(dp, -1, sizeof dp);

    cin>>s>>mod;
    n = sz(s);
    if(!solve(0, 0)) {
    	cout<<"*\n";
    } else {
    	recupera(0,0);
    }

    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}