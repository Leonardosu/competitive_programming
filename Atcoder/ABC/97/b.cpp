#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x;
	cin>>x;

	int last = 1;
	for(int i=2;i*i<=x;++i)
	{
		int j = i;
		while(j*i <= x)
			j*=i;
		last = max(last,j);
	}
	cout<<last<<"\n";
}