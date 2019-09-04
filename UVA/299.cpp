#include <bits/stdc++.h> // UVA 299 - Train Swapping
#define N 80 			// Solution with BIT
using namespace std;

int t,n,x;
int BIT[N];

void upd(int i,int x)
{
	while(i<N)
	{
		BIT[i]+=x;
		i+=i&-i;
	}
}

int query(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans+=BIT[x];
		x-=x&-x;
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;

	while(t--)
	{
		cin>>n; int ans = 0;
		for(int i=0;i<N;++i) BIT[i] = 0;

		for(int i=0;i<n;++i)
		{
			cin>>x;
			ans+=query(n) - query(x);
			upd(x,1);
		}

		cout<<"Optimal train swapping takes "<<ans<<" swaps.\n";
	}
}