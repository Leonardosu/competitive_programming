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
	map<int,int> freq;
	int n, best = 0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		freq[x]++;
		best = max(best ,freq[x]);
	}
	int qnt = n - best;
	while(best < n)
	{
		qnt++;
		best *= 2;
	}
	cout<<qnt<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}