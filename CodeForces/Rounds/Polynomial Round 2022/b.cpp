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
	int n, m, k;
	cin>>n>>m>>k;

	vi cores(m);
	int blocos = n/k;
	int resto = n%k;
	bool ok = true;
	for(int &x : cores) {
		cin>>x;	
		if(x > blocos + 1) ok = false;
		if(x == blocos + 1) resto --;
	}

	if(resto < 0) ok = false;
	cout<<(ok ? "YES" : "NO")<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}