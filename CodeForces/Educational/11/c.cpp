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

    vi v(n);
    for(int &x : v)
    	cin>>x;
    
    int ini = 0;
    int curr = 0;
    int used = 0, ans = 0;
    int l = -1, r = -1;

    while(curr<n) {
    	if(v[curr] == 0)
    		used++;
    	while(ini < curr && k < used) {
    		if(v[ini] == 0) {
    			used--;
    		}    		
    		ini++;
    	}

    	if(k < used) {
    		curr++;
    		continue;
    	}

    	if (curr - ini + 1 > ans) {
    		l = ini;
    		r = curr;
    		ans = curr - ini + 1;
    	}
    	curr++;
    }

    cout<<ans<<"\n";
    for(int i=0;i<n;++i) {
    	if(l<=i && i<=r)
    		cout<<1;
    	else
    		cout<<v[i];
    	cout<<" ";
    }
}