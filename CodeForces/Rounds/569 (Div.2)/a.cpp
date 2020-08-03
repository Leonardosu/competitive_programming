#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

ll f[121];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	f[1] = 1;
	for(int i=2;i<=101;++i)
		f[i] = f[i-1] + (i-1)*4;

	int x;
	cin>>x;
	cout<<f[x]<<"\n";
}