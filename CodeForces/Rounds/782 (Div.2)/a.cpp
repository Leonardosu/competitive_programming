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
	int n,a,b;
	cin>>n>>a>>b;

	int small = a/(b+1);
	int big = small + 1;

	int qntBig = a%(b+1);
	int qntSmall = b - qntBig + 1;

	string ans;
	for(int i=0;i<qntSmall;++i)
	{
		if(i)
			ans += "B";
		for(int j=0;j<small;++j)
			ans += "R";
	}

	for(int i=0;i<qntBig;++i)
	{
		ans += "B";
		for(int j=0;j<big;++j)
			ans += "R";
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