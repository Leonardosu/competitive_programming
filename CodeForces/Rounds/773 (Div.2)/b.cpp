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
	set<int> ss;
	map<int,int> qwe;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		ss.insert(x);
		qwe[x]++;
	}


	int m = ss.size();
	int j = 0;

	vector<int> v(n);
	for(int &x : v)
	{
		x = max(m, ++j);
	}

	for(int &x : v)
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