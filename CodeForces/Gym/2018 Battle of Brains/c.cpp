#include <bits/stdc++.h>
 
using namespace std;
int q;
double l;
int main()
{
	cin>>q;
	for(int i = 1;i<=q;++i)
	{
		cin>>l;
		cout<<fixed<<setprecision(4);
		cout<<"Case "<<i<<": "<<double(l*l/4)<<"\n";
	}
	
}