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


const int inf = 1e9;
vector<int> cost = {
	//  1,2,3,4,5,6,7,8,9
	inf,2,5,5,4,5,6,3,7,6
};
vector<int> valids;


const int N = 1e4 + 7;
int dp[N];

void trivial(int n) {
	int a = -1;
    int b = 11;
    for(int x : valids) {
    	if(cost[x] < b)
    		b = cost[x], a = x;
    	else if(cost[x] == b)
    		a = max(a, x);
    }


    int falta = n - b*(n/b);
    string s = string(n/b, a+'0');
    if(falta) {
    	//aumentar o valor
    	// for(char &c : s) {
    		// int x = c - '0';
    		// for(int y : valids) {
    		// 	if(y > x &&)
    		// }
    	// 	if(falta == 0) break;
    	// }
    }

    // assert(falta == 0);
    // cout<<s<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin>>n>>k;
    for(int i=0;i<k;++i) {
    	int x;
    	cin>>x;
    	valids.pb(x);
    }

    sort(valids.rbegin(), valids.rend());
    dp[0] = 1;    
    for(int i=1;i<=n;++i) {
    	for(int x : valids) {
    		int j = cost[x];
    		if(j <= i) {
    			dp[i] = max(dp[i], dp[i-j] + 1);
    		}
    	}
    }

    string s;
    int free = n;
    while(free) {
    	int digit = -1;
    	int d = 0;
    	for(int x : valids) {
    		int dd = cost[x];
    		if(dd <= free && dp[free-dd] + 1 == dp[free]) {
    			if(x > digit) {
    				digit = x;
    				d = dd;
    			}
    		}
    	}
    	s += digit + '0';
    	free -= d;
    	assert(digit != -1);
    }
    cout<<s<<"\n";
}