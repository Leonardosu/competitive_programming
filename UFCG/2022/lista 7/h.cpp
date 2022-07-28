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

const int N = 105;
const int M = 2005;

int n;
int t[N], d[N], p[N], ord[N];
int dp[N][M];
bool cmp(int i, int j) {
	return d[i] < d[j];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;++i) {
    	cin>>t[i]>>d[i]>>p[i];
    	ord[i] = i;
    }

    sort(ord, ord+n, cmp);
    for(int i=0;i<n;++i){
    	for(int j=0;j<M;++j){
    		dp[i+1][j] = dp[i][j];
    		int k = ord[i];
    		if(t[k] <= j && j < d[k]) {
    			dp[i+1][j] = max(dp[i+1][j], dp[i][j-t[k]] + p[k]);
    		}
    	}
    }

    int j = max_element(dp[n], dp[n] + (M + 1)) - dp[n];
    cout<<dp[n][j]<<"\n";

    vector<int> ans;
    for(int i=n-1;i>=0;--i) {
    	int k = ord[i];
    	if(t[k] <= j && j < d[k] && dp[i][j-t[k]] + p[k] == dp[i+1][j]) {
    		ans.pb(k + 1);
    		j -= t[k];
    	}
    }

    cout<<ans.size()<<"\n";
    for(int i=ans.size()-1;i>=0;--i) {
    	cout<<ans[i]<<" ";
    }
    cout<<"\n";
}