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
	vi v(n);
	for(int &x : v)
		cin>>x;
	
	int best = 0, curr = 0;
	sort(ALL(v));
	for(int &x : v)
	{
		if(x >= curr + 1)
			curr++;
		else
			curr = x;
		best = max(best, curr);
	}
	cout<<best<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	for(int TTT=1;TTT<=T_T;++TTT)
	{
		cout<<"Case #"<<TTT<<": ";
		solve_task();
	}
}