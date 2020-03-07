#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l,r,k,x;
bool flag = false;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>l>>r>>k;
	x = 1;

	ll limit;
	while(true)
	{
		if(l<=x && x<=r) cout<<x<<" ",flag=true;
		limit = r/x;
		if(limit<k) break;
		x*=k;
	}

	if(!flag) cout<<"-1\n";
}