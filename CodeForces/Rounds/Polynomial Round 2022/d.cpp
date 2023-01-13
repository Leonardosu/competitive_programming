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
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v;
	vi row(n);
	int ones = 0;
	for(int i=0;i<n;++i) {
		vi tmp(m);
		for(int j=0;j<m;++j) {
			cin>>tmp[j];
			ones += tmp[j];
			row[i] += tmp[j];
		}
		v.pb(tmp);
	}

	if(ones%n != 0) {
		cout<<"-1\n"; return;
	}

	int target = ones/n;
	int k = 0;
	for(int i=0;i<n;++i)
		if(row[i] > target)
			k += row[i] - target;

	cout<<k<<"\n";
	for(int j=0;j<m;++j) {
		vi sobrou, precisa;
		for(int i=0;i<n;++i) {
			if(row[i] > target && v[i][j] == 1) sobrou.pb(i+1);
			if(row[i] < target && v[i][j] == 0) precisa.pb(i+1);
		}

		int qnt = min(sobrou.size(), precisa.size());
		for(int k=0;k<qnt;++k) {
			cout<<sobrou[k]<<" "<<precisa[k]<<" "<<j+1<<"\n";
			row[sobrou[k]-1]--;
			row[precisa[k]-1]++;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}