/*
	AMR10F SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

int t,a,n,d;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>d;
		cout<< (( (n-1)*d + 2*a )*n)/2<<"\n";
	}
}