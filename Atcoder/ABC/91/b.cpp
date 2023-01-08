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
    map<string, int> qnt;
    cin>>n;
    for(int i=0;i<n;++i) {
    	string s;
    	cin>>s;
    	qnt[s]++;
    }

    cin>>m;
    for(int i=0;i<m;++i) {
    	string s;
    	cin>>s;
    	qnt[s]--;
    }

    int ans = 0;
    for(auto [word, x] : qnt) {
    	ans = max(ans, x);
    }

    cout<<ans<<"\n";
}