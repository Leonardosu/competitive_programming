#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		ll n,x,y;
		bool ans[200];
		memset(ans,false,sizeof(ans));
		cin>>n>>x>>y;

		bool valid1,valid2;
		int mlr = 0;

		for(int r = 1;r<=55;++r)
		{
			if((y - x)%r != 0) continue;
			ll cnt = 0;
			// memset(ans,false,sizeof(ans));
			bool valid = false;

			for(int ini=y; ini>0 && cnt < n;ini-=r) // a[1]
			{
				if(ini == x) valid = true;
				// cout<<ini<<" ";
				cnt++;
			}

			if(!valid) continue;
			
			cnt = 0;
			for(int ini=y; ini>0 && cnt < n;ini-=r) // a[1]
			{
				if(ini == x) valid = true;
				cout<<ini<<" ";
				cnt++;
			}
			while(cnt < n)
			{
				cnt++;
				y+=r;
				cout<<y<<" ";
				
			}
			cout<<"\n";
			break;

		}
	}
	
}
