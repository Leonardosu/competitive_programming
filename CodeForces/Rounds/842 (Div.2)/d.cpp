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

void solve_task()
{
	int n;
	cin>>n;

	vector<pii> v;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin>>x;
    	v.pb({x-1, i});
    }

	sort(ALL(v)); 
	bool vis[n+1]; 
	memset(vis, false, sizeof vis);

    int ans = 0;
 	bool flag = false;
    for (int i = 0; i < n; i++) {
        if (vis[i] || v[i].second == i)
            continue;

        int cycle_size = 0;
        set<int> path;
        int j = i;

        while (!vis[j]) {
        	path.insert(j);
            vis[j] = true;

            j = v[j].second;
            cycle_size++;
        }
 		

        if (cycle_size > 0) {
        	for(auto it : path) {
        		if (present(path, it - 1)) {
        			flag = true;
        		}
        	}
            ans += (cycle_size - 1);
        }
    }
 
    if(!flag) ans++;
    else ans--;

    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}