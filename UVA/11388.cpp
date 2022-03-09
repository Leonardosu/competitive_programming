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

bool prime(int x)
{
	for(int i=2;i*i<=x;++i)
		if(x%i == 0)
			return false;
	return true;
}
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
void solve_task()
{
	int a,b;
	cin>>a>>b;
	if((b%a == 0))
		cout<<a<<" "<<b;
	else
		cout<<"-1";
	cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	while(T_T--)
		solve_task();
}