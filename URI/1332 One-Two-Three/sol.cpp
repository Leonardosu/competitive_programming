/*	
	1332 - One-Two-Three
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string number;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n)
	{
		for(int j=0;j<n;++j)
		{
			cin>>number;
			if(number.size()==5) cout<<"3\n";
			else
			{
				if(number[0]=='t' && number[1]=='w') cout<<"2\n";
				else if(number[0]=='t' && number[2]=='o') cout<<"2\n";
				else if(number[1]=='w' && number[2]=='o') cout<<"2\n";
				else cout<<"1\n";
			}
			
		}
	
	}	

	return 0;
}
