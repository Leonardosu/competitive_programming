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


	int x,y;
	cin>>x>>y;
	int ans = 0;
	//ABCBA
	for(int a=1;a<10;++a)
		for(int b=0;b<10;++b)
			for(int c=0;c<10;++c)
			{
				int n = a*10000 + a + b*1000 + b*10 + c*100;
				if(x<=n && n<=y)
					ans++;
			}

	cout<<ans<<'\n';
}