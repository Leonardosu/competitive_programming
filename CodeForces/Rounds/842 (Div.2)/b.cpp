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
	int n, k;
	cin>>n>>k;

	vi v(n);
	for(int i=0;i<n;++i) {
		int x;
		cin>>x;
		v[i] = x;
	}

	int jafoi = 0;
	int ans = 0, agora = 0;

    for(int i=0;i<n;++i) {
        if(v[i] != i+1-jafoi) {
	        agora++;
	        jafoi++;

	        if(agora == k) {
	            ans++;
	            agora = 0;
	        }
        }
    }

    cout<<(agora > 0 ? ans + 1 :  ans)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}