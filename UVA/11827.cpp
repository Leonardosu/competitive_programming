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

vi v;
int gcd (int a, int b) { while (b) { a %= b,swap(a, b);}return a;}
void solve_task()
{
	string line;
	getline(cin, line);
	istringstream input(line);

	v.clear();
	int n, ans;
	while(input>>n)
		v.pb(n);

	ans = gcd(v[1],v[0]);
	n = v.size();
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			ans = max(ans, gcd(v[i],v[j]));
	cout<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	string s="";
	getline(cin,s);
	while(T_T--)
		solve_task();
}