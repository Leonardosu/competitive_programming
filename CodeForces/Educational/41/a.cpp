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

    int n, m;
    cin>>n>>m;
    int qnt[n+1]; memset(qnt, 0, sizeof qnt);

    for(int i=0;i<m;++i) {
    	int x;
    	cin>>x;
    	qnt[x]++;
    }
    int ans = qnt[1];
    for(int i=1;i<=n;++i)
    	ans = min(ans, qnt[i]);
    cout<<ans<<"\n";
}