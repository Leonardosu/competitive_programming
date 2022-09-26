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

    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;
    int freq[26]; memset(freq,0,sizeof freq);
    for(char c : s)
    	freq[c-'A']++;

    priority_queue<pii> q;
    for(int i=0;i<26;++i) {
    	if(freq[i]) {
    		q.push({freq[i], i});
    	}
    }

    ll ans = 0;
    while(k > 0) {
    	auto [qnt, i] = q.top(); q.pop();
    	ll can = min(k, qnt);

    	ans += can*can;
    	k -= can;
    }

    cout<<ans<<"\n";
}