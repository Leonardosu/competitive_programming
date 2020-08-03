#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5 + 7;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

deque<int> ss;
vector<int> ans,v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n,q,zeros;
	cin>>n;
	v.resize(n);
	ans.resize(n);

	for(int i=0;i<n;++i)
	{
		cin>>v[i];
		ans[i] = v[i];
		if(v[i] == 0) zeros++;
	}

	if(n%2)
	{
		if(zeros == n)
		{
			for(int i=0;i<n;++i)
				ans[i] = 0;
		}
		else
		{
			int id,best = -1;

			for(int i=0;i<n;++i)
			{
				if(ans[i] > 0 && best < ans[i])
					best = ans[i],id = i;

				if(ans[i] < 0 && -ans[i] - 1 > best)
					best = -ans[i] - 1,id = i; 
			}

			if(best == -1)
			{
				for(int i=0;i<n;++i)
					ans[i] = 0;
			}
			else
			{
				for(int i=0;i<n;++i)
					if(ans[i] >= 0 && i != id)
						ans[i] = -ans[i] - 1;
				ans[id] = best;
			}
		}		
	}
	else
	{
		for(int i=0;i<n;++i)
			if(ans[i] >= 0)
				ans[i] = -ans[i] - 1;
	}

	for(int i=0;i<n;++i)
		cout<<ans[i]<<" ";
	cout<<"\n";
}