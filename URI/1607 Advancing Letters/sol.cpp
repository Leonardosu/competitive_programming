/*			
	1607 - Advancing Letters
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

int n,cont;
string name1,name2;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	while(n--)
	{
	  cont=0;
		cin>>name1>>name2;
		for(int i=0;i<name1.size();++i)
		{
			int a=name1[i],b=name2[i];
			if(a<=b)
		  		cont+=name2[i]-name1[i];
		  	else
		  		cont+=26-(a-b);

		}
		cout<<cont<<'\n';
	}
	
	
	return 0;
}