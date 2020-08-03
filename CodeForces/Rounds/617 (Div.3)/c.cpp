#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

map<ii,int> save;
int t,n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		save.clear();
		cin>>n;
		ii now = {0,0};
		int best = 1e9;
		int l,r;
		save[now] = 0;

		for(int i=0;i<n;++i)
		{
			char x;
			cin>>x;
			if(x == 'L') now.f+=1;
			if(x == 'R') now.f+=-1;
			if(x == 'U') now.s+=1;
			if(x == 'D') now.s+=-1;

			if(save.count(now))
			{
				int dif = i - save[now] + 1;
				if(dif < best)
					best = dif,l = save[now],r = i;
			}
			save[now] = i+1;
		}

		if(best == 1e9) cout<<"-1\n";
		else cout<<l+1<<" "<<r+1<<"\n";
	}	
}