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

    int n,m;
    cin>>n>>m;
    vector<pii> a, b;
    for(int i=0;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	if(x==1) {
    		a.pb({y, i+1});
    	} else {
    		b.pb({y, i+1});
    	}
    }

    sort(ALL(a), greater<pii>());
    sort(ALL(b), greater<pii>());

    vi sum_a(sz(a) + 1);
    vi sum_b(sz(b) + 1);
    sum_a[0] = sum_b[0] = 0;

    for(int i=0;i<sz(a);++i)
    	sum_a[i + 1] = sum_a[i] + a[i].f;
    for(int i=0;i<sz(b);++i)
    	sum_b[i + 1] = sum_b[i] + b[i].f;

    int best = -1, best_i = -1;
    for(int i=0;i<=sz(b) && i * 2 <= m; ++i) {
    	int j = min(sz(a), m - i*2);
    	if(best < sum_b[i] + sum_a[j]) {
    		best = sum_b[i] + sum_a[j];
    		best_i = i;
    	}
    }

    cout<<best<<"\n";
    int best_j = min(sz(a), m - best_i * 2);
    bool first = true;
    for(int i=0;i<best_i;++i) {
    	if(first) first = false;
    	else cout<<' ';
    	cout<<b[i].s;
    }

    for(int i=0;i<best_j;++i) {
    	if(first) first = false;
    	else cout<<' ';
    	cout<<a[i].s;
    }
    cout<<"\n";
}