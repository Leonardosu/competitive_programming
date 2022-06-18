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

const int N = 2e5 + 7;
int pai[N], l[N], r[N], lv[N], val[N];
bool finished[N];

void clear(int n) {
	val[1] = 0;
	for(int i=2;i<=n;++i)
		finished[i] = false, lv[i] = val[i] = 0;
}

void solve_task()
{
	int n;
	cin>>n;
	clear(n);

	for(int i=2;i<=n;++i)
	{
		cin>>pai[i];
		lv[pai[i]]++;
	}

	for(int i=1;i<=n;++i)
		cin>>l[i]>>r[i];

	queue<int> nodes;
	for(int i=1;i<=n;++i)
		if(lv[i] == 0)
			nodes.push(i);

	int moves = 0;
	while(!nodes.empty()) {
		int x = nodes.front(); nodes.pop();
		int y = pai[x];

		lv[y]--;
		if(lv[y] == 0)
			nodes.push(y);

		if (l[x] <= val[x] && val[x] <= r[x])
      	{
        	val[y] = min(r[y], val[y] + val[x]);
        	continue;
      	}

      	val[x] = r[x];
      	val[y] = min(r[y], val[y] + val[x]);		
		moves++;
	}
	cout<<moves<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}