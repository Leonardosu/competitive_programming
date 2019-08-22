/*					
	1871 - Zero means Zero
	Leonardo Su 	
	3/16/17, 3:08:46 PM
*/
#include <bits/stdc++.h>
using namespace std;

int a,b,sum;
string number;

int main()
{
	ios_base::sync_with_stdio(false); //cin.tie(0);
	
	while(cin>>a>>b && a+b)
	{
		sum=a+b;
		number=to_string(sum);
		for(int i=0;i<number.size();++i)
			if(number[i]!='0') cout<<number[i];
		
		cout<<"\n";
	}
	
	return 0;
}