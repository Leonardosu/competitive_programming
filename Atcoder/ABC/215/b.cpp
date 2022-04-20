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
	int TT = 1;
	// cin>>TT;
	while(TT--)
	{
		ll n;
		cin>>n;
		int k = 0;
		for(int i=63;i>=0;--i)	
		{
			if(n & (1LL<<i))
			{

				k = i;
				break;
			}
		
		}

		cout<<k<<"\n";
	}	
}