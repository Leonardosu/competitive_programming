/*
	LASTDIG SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

int t,a,b;

int pow(int a,int b)
{
	int prod=1;
	for(int i=1;i<=b;++i)
		prod*=a;
	return prod;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a == 0 && b != 0)
			{cout<<"0\n"; continue;}
		if(b == 0)
			{cout<<"1\n"; continue;}


		a = a%10;
		b = b%4;
		if(b == 0) b = 4;

		a = pow(a,b);

		cout<<a%10<<"\n";
	}
}