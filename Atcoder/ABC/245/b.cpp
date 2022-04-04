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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	int N = 2010;
	vi v(N,0);
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		v[x]++;
	}
	
	int qnt = 0;
	for(int i=0;i<N;++i)
	{
		if(v[i] == 0)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<"2001\n";
	return 0;
}