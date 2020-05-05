#include <bits/stdc++.h>
using namespace std;
long long int x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>x;
	cout<<x;
	while(x > 1)
	{
		cout<<" ";
		if(x%2 == 0) x/=2;
		else x*=3,x++;
		cout<<x;
	}
	cout<<"\n";
}
