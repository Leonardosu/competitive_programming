#include "bits/stdc++.h"
// #define f first
// #define s second
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
	int n,k;
	string s;

	cin>>n>>k;
	cin>>s;
	vector<int> ans(n, 0);

	if(k&1)
	{
		for(char &c : s)
			c = (c == '0' ? '1' : '0');
	}

	for(int i=0;i<n;++i)
		if(s[i] == '0' && k)
			s[i] = '1', k--, ans[i]++;

	if(k&1)
		s[n-1] = '0';
	ans[n-1] += k;

	cout<<s<<"\n";
	for(int &x : ans)
		cout<<x<<" ";
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