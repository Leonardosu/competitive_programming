#include <bits/stdc++.h>

using namespace std;


int t;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	while(t--)
	{
		int n; int ans = 0;
		double x;
		cin>>n>>x; 
		int mini = ceil(double(n*x));

		for(int i=0;i<n;++i)
		{
			cin>>x;			
			if(x>=50)
				ans++;
		}
		if(ans>=mini)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}