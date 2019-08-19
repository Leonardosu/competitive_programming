/*
	INTEST SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

int n,k,qnt,x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>n>>k;
	while(n--)
	{
		cin>>x;
		if(x%k == 0) qnt++;
	}
	cout<<qnt<<"\n";	
}