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

const int N = 100005;
int vis[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    while(n--) {
    	int l, r;
    	cin>>l>>r;
    	vis[l]++;
    	vis[r+1]--;
    }

    int cnt = 0;
    for(int i=1;i<N;++i) {
    	vis[i] += vis[i-1];
    	if(vis[i] > 0)
    		cnt++;
    }

    cout<<cnt<<endl;
}