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
	bool possible = false;
	for(int &x : v) {
		int y;
		cin>>y;
		if(y < k) x = -1;
		else if(y == k) x = 0;
		else x = 1;

		if(x == 0)
			possible = true;
	}

	if(!possible) {
		cout<<"no\n";
		return;
	}

	possible = false;
	for(int i=0;i+1<n;++i) 
		if(v[i] >= 0 && v[i+1] >= 0) {
			possible = true;
			break;
		}

	for(int i=0;i+2<n;++i)
		if(v[i] >=0 && v[i+2] >= 0) {
			possible = true;
			break;
		}
	
		
	
	cout<<((n == 1 || possible) ? "yes" : "no")<<"\n";		
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	while(T_T--)
		solve_task();
}