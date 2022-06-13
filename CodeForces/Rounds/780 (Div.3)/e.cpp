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

const int N = 2e3 + 3;

void solve_task()
{
	int n;
	cin>>n;

	int total = 0;
	map<int,int> freq;

	for(int i=0;i<n;++i)
	{
		string s;
		cin>>s;
		for(int j=0;j<n;++j)
		{
			int x = s[j] - '0';
			freq[i-j] += x;
			total += x;
		}
	}

	int diagonal = 0;
	for(int k=0;k<n;++k)
		diagonal = max(diagonal, freq[k] + freq[k-n]);	
	
	cout<<(n - diagonal) + (total - diagonal)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}