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

const int N = 2e5 + 7;
vector<int> g[N];
bool mark[N];
int lv[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
        lv[x]++, lv[y]++;
    }

    int ans = 0;
    queue<int> fila;
    for(int i=1;i<=n;++i) {
        if(lv[i] == 1) {
            fila.push(i);
        }
    }

    while(!fila.empty()) {
        int x = fila.front();
        fila.pop();

        if(!mark[x]) {
            for(int y : g[x]) {
                if(!mark[y]) {
                    ans++;
                    mark[x] = mark[y] = true;
                }
            }
        }

        for(int y : g[x]) {
            lv[y]--;
            if(lv[y] == 1) {
                fila.push(y);
            }
        }
    }
    cout<<ans<<"\n";
}