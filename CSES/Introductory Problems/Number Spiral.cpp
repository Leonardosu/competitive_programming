#include <bits/stdc++.h>
using namespace std;

int t;
long long int i,j,ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>t;
	while(t--)
	{
		cin>>i>>j;
		if(i == j) ans = i*i - i + 1LL;
		else if(i > j)
		{
			if(i%2LL == 0LL) ans = i*i - j + 1LL;
			else ans = (i-1LL)*(i-1LL) + j;
		}
		else
		{
			if(j%2LL == 1LL) ans = j*j - i + 1LL;
			else ans = (j-1LL)*(j-1LL) + i;
		}

		cout<<ans<<"\n"; 
	}

}