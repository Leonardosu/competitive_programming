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

bool valid(vector<int> &freq, int mid)
{
	int k = mid;
	for(int &x : freq)
	{
		if(x > mid)
			k -= (x-mid);
		else
			break;

		if(k < 0)
			return false;
	}
	return (k >= 0);
}

void solve_task()
{
	int n, x;
	cin>>n;
	vector<int> freq(n+1, 0);

	int qnt = 1;
	freq[0] = 1;
	for(int i=1;i<n;++i)
	{
		cin>>x;
		if(freq[x] == 0)
			qnt++;
		freq[x]++;
	}

	sort(ALL(freq), greater<int>());

	for(int i=0;i<=n;++i)
	{
		if(!freq[i]) break;
		freq[i] -= qnt - i;
	}

	sort(ALL(freq), greater<int>());
	while(!freq.empty() && freq.back() <= 0)
		freq.pop_back();
	
	int l = 0, r = 3*n;
	int plus = 0;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(valid(freq, mid))
			plus = mid, r = mid - 1;
		else
			l = mid + 1;
	}

	cout<<qnt + plus<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}