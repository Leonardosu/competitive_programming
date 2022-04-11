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

	int n;
	cin>>n;
	int qnt = 0,x;
	for(int i=1;i<=n;++i)
	{
		cin>>x;
		while(x%2 == 0)
			x>>=1,qnt++;
	}
	cout<<qnt<<"\n";
}