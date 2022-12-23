#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;


typedef long long int ll;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
const ll p1 = 311;

vector<ll> prefix, suffix;
int n;
inline ll poww(ll a, ll b){ll res = 1LL;while (b > 0LL){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}

void init(string s)
{
	prefix.resize(n);
	suffix.resize(n);
	ll x = 0;
	ll b1 = 1LL;
	for(int i=0;i<n;++i)
	{
		x = (x + s[i]*b1)%mod;
 		prefix[i] = (x + mod)%mod;
		b1 = (b1*p1)%mod;
	}
 	
 	x = 0;
	b1 = 1LL;
 	for(int i=n-1;i>=0;--i)
	{
		x = (x + s[i]*b1)%mod;
 		suffix[i] = (x + mod)%mod;
		b1 = (b1*p1)%mod;
	}
}


void solve_task()
{
	string s;
	cin>>n>>s;
	int balance = 0,resto = n, last = 0, qnt = 0;
	init(s);
	bool can = true;
	for(int i=0;i<n;++i)
	{
		balance += (s[i] == '(' ? 1 : -1);
		if(balance == 0 && can)
		{
			resto -= (i - last + 1);
			last = i + 1;
			qnt++;
			balance = 0;
		}
		else
		{
			if(balance < 0)
				can = false;

			if(last == i)
				continue;

			ll left = prefix[i];
			if(last)
				left -= prefix[last - 1];
			if(left < 0)
				left += mod;


			ll right = suffix[last];
			if(i+1<n)
				right -= suffix[i+1];
			if(right < 0)
				right += mod;


			ll base1 = poww(p1, last);
			ll base2 = poww(p1, n - i - 1);
			left = (left * poww(base1, mod-2))%mod;
			right = (right * poww(base2, mod-2))%mod;

			if(left == right)
			{
				resto -= (i - last + 1);
				can = true;
				last = i + 1;
				qnt ++;
				balance = 0;
			}
		}
	}

	cout<<qnt<<" "<<resto<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}