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
	string s; int n;
	cin>>n>>s;
	string ans = "";
	int qnt = 0;
	for(char &c : s) 
		if(c == '1') qnt++;
	
	for(int i=1;i<n;++i) {
		if(s[i] == '0')
			ans += '+';
		else {
			if(qnt&1)
				ans += '+';
			else ans += '-';
			qnt--;
		}
	}

	cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}