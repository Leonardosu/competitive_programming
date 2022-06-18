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
	ll sum = 0;

	cin>>n;
	vi v(n);
	for(int i=0;i<n;++i) {
		cin>>v[i];
		sum += v[i];
	}

	if(sum == 0) {
		reverse(ALL(v));
		sum = 0;
		bool flag = true;
		v.pop_back();
		for(int &x : v) {
			sum += x;
			if(0 < sum || !(sum != 0 || x == 0)) 
				flag = false;
		}
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	else
		cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}