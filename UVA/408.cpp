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
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
void solve_task(int step, int mod)
{
	string ans = (gcd(step, mod) == 1? "Good" : "Bad");
	cout<<setw(10)<<step<<setw(10)<<mod<<"    " + ans + " Choice"<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1, step, mod;
	while(cin>>step)
	{
		cin>>mod;
		solve_task(step, mod);
		cout<<"\n";
	}
}